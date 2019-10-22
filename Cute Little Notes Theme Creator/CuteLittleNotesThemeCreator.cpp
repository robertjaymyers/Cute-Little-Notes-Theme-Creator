#include "CuteLittleNotesThemeCreator.h"
#include <QCloseEvent>
#include <QInputDialog>
#include <QColorDialog>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <string>
#include <fstream>

// General concept: User clicks on different areas of the UI, which brings up an option to set style elements (ex: color).
// File > Save As / Save can save the style settings in a format that can then be parsed by Cute Little Notes.

CuteLittleNotesThemeCreator::CuteLittleNotesThemeCreator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	prefLoad();

	initTextEditContents = ui.textEdit->toHtml();

	setWindowTitle(winTitleUntitled + winTitlePlaceholder + " - " + winTitleProgramName);
	statusBarInit();

	ui.menuJot->menuAction()->setVisible(false);
	ui.menuEdit->menuAction()->setVisible(false);
	ui.menuView->menuAction()->setVisible(false);

	ui.actionNew->setShortcut(Qt::Key_N | Qt::ControlModifier);
	ui.actionOpen->setShortcut(Qt::Key_O | Qt::ControlModifier);
	ui.actionSave->setShortcut(Qt::Key_S | Qt::ControlModifier);
	ui.actionSaveAs->setShortcut(Qt::Key_S | Qt::ControlModifier | Qt::ShiftModifier);

	connect(ui.actionNew, &QAction::triggered, this, &CuteLittleNotesThemeCreator::fileNew);
	connect(ui.actionOpen, &QAction::triggered, this, &CuteLittleNotesThemeCreator::fileOpen);
	connect(ui.actionSave, &QAction::triggered, this, &CuteLittleNotesThemeCreator::fileSaveOps);
	connect(ui.actionSaveAs, &QAction::triggered, this, &CuteLittleNotesThemeCreator::fileSaveAs);
	connect(ui.actionExit, &QAction::triggered, this, &CuteLittleNotesThemeCreator::close);

	refreshStatusTips();
	connect(ui.actionSetCreatorName, &QAction::triggered, this, [=]() {
		setThemeInfoName(themeInfoCreatorName, "Creator");
		refreshStatusTips();
	});
	connect(ui.actionSetThemeName, &QAction::triggered, this, [=]() {
		setThemeInfoName(themeInfoThemeName, "Theme");
		refreshStatusTips();
	});
	connect(ui.actionSetVersionNumber, &QAction::triggered, this, &CuteLittleNotesThemeCreator::setThemeInfoVersionNumber);

	ui.textEdit->setObjectName(themeObjStr_textEdit);
	ui.mainToolBar->setObjectName(themeObjStr_mainToolBar);
	ui.menuBar->setObjectName(themeObjStr_menuBar);
	ui.menuDropdown->setObjectName(themeObjStr_menuDropdown);
	ui.statusBar->setObjectName(themeObjStr_statusBar);

	// Give toolbar button instance of action a unique name, so that it can be referenced in stylesheet.
	ui.mainToolBar->widgetForAction(ui.actionNew)->setObjectName("toolbarButtonActionNew");
	ui.mainToolBar->widgetForAction(ui.actionOpen)->setObjectName("toolbarButtonActionOpen");
	ui.mainToolBar->widgetForAction(ui.actionSave)->setObjectName("toolbarButtonActionSave");
	ui.mainToolBar->widgetForAction(ui.actionComment)->setObjectName("toolbarButtonActionComment");
	ui.mainToolBar->widgetForAction(ui.actionListTitle)->setObjectName("toolbarButtonActionListTitle");
	ui.mainToolBar->widgetForAction(ui.actionMarkDone)->setObjectName("toolbarButtonActionMarkDone");
	ui.mainToolBar->widgetForAction(ui.actionMarkScrapped)->setObjectName("toolbarButtonActionMarkScrapped");

	ui.mainToolBar->insertSeparator(ui.actionComment); // Comment is 1st icon in Jot section of toolbar, so we place separator before it.

	/*QFile stylesheetFile("stylesheetTemplate.qss");
	if (stylesheetFile.open(QFile::ReadOnly))
	{
		QString stylesheetTemp = QLatin1String(stylesheetFile.readAll());
		this->setStyleSheet(stylesheetTemp);
	}*/

	setStyleSheetToDefault();

	ui.textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.textEdit, &QTextEdit::customContextMenuRequested, this, [=]() {
		debugMsgCssModified(ui.textEdit->objectName(), ui.textEdit->styleSheet(), "Current ");
		QString revisedStylesheet = dialogChooseThemeProperty(ui.textEdit->objectName(), ui.textEdit->styleSheet());
		if (!revisedStylesheet.isEmpty())
		{
			ui.textEdit->setStyleSheet(revisedStylesheet);
			fileDocumentModified();
		}
		debugMsgCssModified(ui.textEdit->objectName(), ui.textEdit->styleSheet(), "Modified");
	});

	ui.mainToolBar->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.mainToolBar, &QTextEdit::customContextMenuRequested, this, [=]() {
		debugMsgCssModified(ui.mainToolBar->objectName(), ui.mainToolBar->styleSheet(), "Current ");
		QString revisedStylesheet = dialogChooseThemeProperty(ui.mainToolBar->objectName(), ui.mainToolBar->styleSheet());
		if (!revisedStylesheet.isEmpty())
		{
			ui.mainToolBar->setStyleSheet(revisedStylesheet);
			fileDocumentModified();
		}
		debugMsgCssModified(ui.mainToolBar->objectName(), ui.mainToolBar->styleSheet(), "Modified");
	});

	ui.menuBar->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.menuBar, &QTextEdit::customContextMenuRequested, this, [=]() {
		debugMsgCssModified(ui.menuBar->objectName(), ui.menuBar->styleSheet(), "Current ");
		QString revisedStylesheet = dialogChooseThemeProperty(ui.menuBar->objectName(), ui.menuBar->styleSheet());
		if (!revisedStylesheet.isEmpty())
		{
			ui.menuBar->setStyleSheet(revisedStylesheet);
			fileDocumentModified();
		}
		debugMsgCssModified(ui.menuBar->objectName(), ui.menuBar->styleSheet(), "Modified");
	});

	ui.menuDropdown->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.menuDropdown, &QTextEdit::customContextMenuRequested, this, [=]() {
		debugMsgCssModified(ui.menuDropdown->objectName(), ui.menuDropdown->styleSheet(), "Current ");
		QString revisedStylesheet = dialogChooseThemeProperty(ui.menuDropdown->objectName(), ui.menuDropdown->styleSheet());
		if (!revisedStylesheet.isEmpty())
		{
			ui.menuDropdown->setStyleSheet(revisedStylesheet);
			fileDocumentModified();
		}
		debugMsgCssModified(ui.menuDropdown->objectName(), ui.menuDropdown->styleSheet(), "Modified");
	});

	ui.statusBar->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.statusBar, &QTextEdit::customContextMenuRequested, this, [=]() {
		debugMsgCssModified(ui.statusBar->objectName(), ui.statusBar->styleSheet(), "Current ");
		QString revisedStylesheet = dialogChooseThemeProperty(ui.statusBar->objectName(), ui.statusBar->styleSheet());
		if (!revisedStylesheet.isEmpty())
		{
			ui.statusBar->setStyleSheet(revisedStylesheet);
			fileDocumentModified();
		}
		debugMsgCssModified(ui.statusBar->objectName(), ui.statusBar->styleSheet(), "Modified");
	});

	connect(ui.actionPrefCommentSetColorBg, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotCommentBg);
	});
	connect(ui.actionPrefCommentSetColorText, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotCommentText);
	});
	connect(ui.actionPrefListTitleSetColorBg, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotListTitleBg);
	});
	connect(ui.actionPrefListTitleSetColorText, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotListTitleText);
	});
	connect(ui.actionPrefMarkDoneSetColorBg, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotMarkDoneBg);
	});
	connect(ui.actionPrefMarkDoneSetColorText, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotMarkDoneText);
	});
	connect(ui.actionPrefMarkDoneSetText, &QAction::triggered, this, [=]() {
		setThemeMiscText(textJotMarkDone);
	});
	connect(ui.actionPrefMarkScrappedSetColorBg, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotMarkScrappedBg);
	});
	connect(ui.actionPrefMarkScrappedSetColorText, &QAction::triggered, this, [=]() {
		setThemeMiscColor(colorJotMarkScrappedText);
	});
	connect(ui.actionPrefMarkScrappedSetText, &QAction::triggered, this, [=]() {
		setThemeMiscText(textJotMarkScrapped);
	});

	connect(ui.actionComment, &QAction::triggered, this, &CuteLittleNotesThemeCreator::jotComment);
	connect(ui.actionListTitle, &QAction::triggered, this, &CuteLittleNotesThemeCreator::jotListTitle);
	connect(ui.actionMarkDone, &QAction::triggered, this, &CuteLittleNotesThemeCreator::jotMarkDone);
	connect(ui.actionMarkScrapped, &QAction::triggered, this, &CuteLittleNotesThemeCreator::jotMarkScrapped);
}

QString CuteLittleNotesThemeCreator::dialogChooseThemeProperty(const QString &objName, const QString &objStylesheet)
{
	QStringList themeProperties;
	themeCssMapIterator = themeCssMap.find(objName);
	if (themeCssMapIterator == themeCssMap.end())
		return QString();
	themeProperties = themeCssMapIterator->second;

	bool ok;
	QString themeProperty = QInputDialog::getItem(
		this,
		"Editing: " + objName,
		tr("Theme Property:"),
		themeProperties,
		0,
		false,
		&ok,
		Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

	if (ok && !themeProperty.isEmpty())
	{
		std::string objStylesheetAsStdStr = objStylesheet.toStdString();

		themePropertyMapIterator = themePropertyMap.find(themeProperty);
		if (themePropertyMapIterator == themePropertyMap.end())
			return QString();

		if (objStylesheetAsStdStr.find(themePropertyMapIterator->second.toStdString()) == std::string::npos)
			return QString();

		if (themePropertyMapIterator->second.toStdString().find("url(") != std::string::npos)
		{
			// Input type is image, do open file dialog to pick image
			// otherwise, skip past and do color operations as normal
			QString filename = QFileDialog::getOpenFileName(this, tr("Choose Icon"), fileDirLastOpened, tr("IMG Files (*.png *.jpg *.ico)"));
			if (filename.isEmpty())
				return QString();

			statusBar()->showMessage(tr("Icon loaded"), 2000);
			fileDirLastOpened = QFileInfo(filename).path();

			if (objStylesheetAsStdStr.find(themePropertyMapIterator->second.toStdString()) == std::string::npos)
				return QString();

			int posBegin = objStylesheetAsStdStr.find(themePropertyMapIterator->second.toStdString());
			int posEnd = objStylesheetAsStdStr.find(";", posBegin) + 1;

			objStylesheetAsStdStr.erase(posBegin, posEnd - posBegin);
			objStylesheetAsStdStr.insert(posBegin, (themePropertyMapIterator->second + filename + ");").toStdString());

			return QString::fromStdString(objStylesheetAsStdStr);
		}

		// Retrieve property's current color, so it can be displayed in getColor interface.
		QColor propertyCurrentColor;
		{
			int posBeginProperty = objStylesheetAsStdStr.find(themePropertyMapIterator->second.toStdString());
			int posBegin = objStylesheetAsStdStr.find("#", posBeginProperty);
			int posEnd = objStylesheetAsStdStr.find(";", posBegin);
			std::string propertyCurrentColorAsStdString = "";
			propertyCurrentColorAsStdString.append(objStylesheetAsStdStr, posBegin, posEnd - posBegin);
			//qDebug() << QString::fromStdString(propertyCurrentColorAsStdString);
			propertyCurrentColor = QColor(QString::fromStdString(propertyCurrentColorAsStdString));
		}
		//qDebug() << propertyCurrentColor.name();

		QColor themePropertyColor = QColorDialog::getColor(propertyCurrentColor, this, "Choose Color");
		if (!themePropertyColor.isValid())
			return QString();

		themePropertyMapIterator = themePropertyMap.find(themeProperty);
		if (themePropertyMapIterator == themePropertyMap.end())
			return QString();

		if (objStylesheetAsStdStr.find(themePropertyMapIterator->second.toStdString()) != std::string::npos)
		{
			int posBegin = objStylesheetAsStdStr.find(themePropertyMapIterator->second.toStdString());
			int posEnd = objStylesheetAsStdStr.find(";", posBegin) + 1;

			objStylesheetAsStdStr.erase(posBegin, posEnd - posBegin);
			objStylesheetAsStdStr.insert(posBegin, (themePropertyMapIterator->second + themePropertyColor.name() + ";").toStdString());
			//objStylesheetAsStdStr.insert(posBegin, themePropertyMapIterator->second.arg(themePropertyColor.name()).toStdString());

			return QString::fromStdString(objStylesheetAsStdStr);
		}

		//return themePropertyMapIterator->second.arg(themePropertyColor.name());

		//ui.textEdit->setStyleSheet(ui.textEdit->styleSheet().append(themePropertyMapIterator->second.arg(themePropertyColor.name())));
		//qDebug() << themePropertyMapIterator->second.arg(themePropertyColor.name());
	}

	return QString();
}

void CuteLittleNotesThemeCreator::debugMsgCssModified(const QString &objName, const QString &objStylesheet, const QString modifType)
{
	qDebug() << objName + " CSS " + modifType + ": " + objStylesheet;
}

std::string CuteLittleNotesThemeCreator::extractSubstring(const std::string strBegin, const std::string strEnd, const std::string &strExtractFrom)
{
	std::string extracted = "";
	int posFound = 0;
	while (strExtractFrom.find(strBegin, posFound) != std::string::npos)
	{
		int posBegin = strExtractFrom.find(strBegin, posFound);
		int posEnd = strExtractFrom.find(strEnd, posBegin) + 1;
		extracted.append(strExtractFrom, posBegin, posEnd - posBegin);
		posFound = posEnd;
	}
	return extracted;
}

std::string CuteLittleNotesThemeCreator::extractSubstringInbetween(const std::string strBegin, const std::string strEnd, const std::string &strExtractFrom)
{
	std::string extracted = "";
	int posFound = 0;
	while (strExtractFrom.find(strBegin, posFound) != std::string::npos)
	{
		int posBegin = strExtractFrom.find(strBegin, posFound) + strBegin.length();
		int posEnd = strExtractFrom.find(strEnd, posBegin) + 1 - strEnd.length();
		extracted.append(strExtractFrom, posBegin, posEnd - posBegin);
		posFound = posEnd;
	}
	return extracted;
}

std::string CuteLittleNotesThemeCreator::replaceSubstring(const std::string strBegin, const std::string strEnd, const std::string strMid, const std::string strStylesheet)
{
	int posBegin = strStylesheet.find(strBegin);
	int posEnd = strStylesheet.find(strEnd, posBegin) + 1;

	std::string strStylesheetCopy = strStylesheet;
	strStylesheetCopy.erase(posBegin, posEnd - posBegin);
	strStylesheetCopy.insert(posBegin, (strBegin + strMid + strEnd));

	return strStylesheetCopy;
}

void CuteLittleNotesThemeCreator::refreshStatusTips()
{
	ui.actionSetCreatorName->setStatusTip(actionSetCreatorName_statusTip.arg(themeInfoCreatorName));
	ui.actionSetThemeName->setStatusTip(actionSetThemeName_statusTip.arg(themeInfoThemeName));
	ui.actionSetVersionNumber->setStatusTip(actionSetVersionNumber_statusTip.arg(themeInfoVersionNum));
}

void CuteLittleNotesThemeCreator::statusBarInit()
{
	statusBar()->showMessage(tr("Ready"));
}

void CuteLittleNotesThemeCreator::setStyleSheetToDefault()
{
	ui.textEdit->setStyleSheet(textEditStyleSheetDefault);
	ui.mainToolBar->setStyleSheet(mainToolBarStyleSheetDefault);
	ui.menuBar->setStyleSheet(menuBarStyleSheetDefault);
	ui.menuFile->setStyleSheet(dropdownMenuStyleSheetDefault);
	ui.menuSetThemeInfo->setStyleSheet(dropdownMenuStyleSheetDefault);
	ui.menuSetThemePreferencesMisc->setStyleSheet(dropdownMenuStyleSheetDefault);
	ui.menuDropdown->setStyleSheet(dropdownMenuStyleSheetDefault);
	ui.statusBar->setStyleSheet(statusBarStyleSheetDefault);
}

void CuteLittleNotesThemeCreator::closeEvent(QCloseEvent *event)
{
	if (fileSaveModifCheck())
	{
		prefSave();
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void CuteLittleNotesThemeCreator::fileDocumentModified()
{
	themeModifiedUnsaved = true;
	setWindowModified(themeModifiedUnsaved);
}

void CuteLittleNotesThemeCreator::fileSetCurrent(const QString &filename)
{
	fileCurrent = filename;
	themeModifiedUnsaved = false;
	setWindowModified(false);

	QString displayName;
	if (fileCurrent.isEmpty())
	{
		displayName = winTitleUntitled;
	}
	else
	{
		displayName = QFileInfo(fileCurrent).fileName();
	}
	setWindowTitle(displayName + winTitlePlaceholder + " - " + winTitleProgramName);
}

void CuteLittleNotesThemeCreator::fileNew()
{
	if (fileSaveModifCheck())
	{
		ui.textEdit->clear();
		ui.textEdit->setHtml(initTextEditContents);
		setStyleSheetToDefault();
		fileSetCurrent(QString());
	}
}

void CuteLittleNotesThemeCreator::fileOpen()
{
	if (fileSaveModifCheck())
	{
		QString filename = QFileDialog::getOpenFileName(this, tr("Open"), fileDirLastOpened, tr("QSS Files (*.qss)"));
		if (!filename.isEmpty())
		{
			std::string fileContents = "";
			std::string line;
			std::ifstream fileRead(filename.toStdString());
			while (std::getline(fileRead, line))
			{
				fileContents += line;
			}
			fileRead.close();

			QString textEditStyle = QString::fromStdString(extractSubstring("QTextEdit{", "}", fileContents));
			textEditStyle.append(QString::fromStdString(extractSubstring("QScrollBar{", "}", fileContents)));
			qDebug() << textEditStyle;
			ui.textEdit->setStyleSheet(textEditStyle);

			QString mainToolBarStyle = QString::fromStdString(extractSubstring("QToolBar{", "}", fileContents));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolBar::separator{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton:hover{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionNew{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionOpen{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionSave{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionComment{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionListTitle{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionMarkDone{", "}", fileContents)));
			mainToolBarStyle.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionMarkScrapped{", "}", fileContents)));
			qDebug() << mainToolBarStyle;
			ui.mainToolBar->setStyleSheet(mainToolBarStyle);

			QString menuBarStyle = QString::fromStdString(extractSubstring("QMenuBar{", "}", fileContents));
			menuBarStyle.append(QString::fromStdString(extractSubstring("QMenuBar::item:selected{", "}", fileContents)));
			qDebug() << menuBarStyle;
			ui.menuBar->setStyleSheet(menuBarStyle);

			QString menuDropdownStyle = QString::fromStdString(extractSubstring("QMenu{", "}", fileContents));
			menuDropdownStyle.append(QString::fromStdString(extractSubstring("QMenu::separator{", "}", fileContents)));
			menuDropdownStyle.append(QString::fromStdString(extractSubstring("QMenu::item{", "}", fileContents)));
			menuDropdownStyle.append(QString::fromStdString(extractSubstring("QMenu::item:selected{", "}", fileContents)));
			menuDropdownStyle.append(QString::fromStdString(extractSubstring("QMenu::indicator:non-exclusive:checked{", "}", fileContents)));
			qDebug() << menuDropdownStyle;
			ui.menuDropdown->setStyleSheet(menuDropdownStyle);

			QString statusBarStyle = QString::fromStdString(extractSubstring("QStatusBar{", "}", fileContents));
			qDebug() << statusBarStyle;
			ui.statusBar->setStyleSheet(statusBarStyle);

			{
				const QString fpath = QFileInfo(filename).path() + "/" + QFileInfo(filename).baseName() + "_themeInfo.ini";
				qDebug() << "fpath: " + fpath;
				QSettings settings(fpath, QSettings::IniFormat);
				settings.beginGroup("ModInfo");
				if (!settings.value("creatorName").isNull())
					themeInfoCreatorName = settings.value("creatorName").toString();
				if (!settings.value("themeUniqueName").isNull())
					themeInfoThemeName = settings.value("themeUniqueName").toString();
				if (!settings.value("versionNumber").isNull())
					themeInfoVersionNum = settings.value("versionNumber").toDouble();
				settings.endGroup();
				refreshStatusTips();
			}

			{
				const QString fpath = QFileInfo(filename).path() + "/" + QFileInfo(filename).baseName() + "_themeJot.ini";
				QSettings settings(fpath, QSettings::IniFormat);
				settings.beginGroup("JotSettings");
				if (!settings.value("textJotMarkDone").toString().isEmpty())
					textJotMarkDone = settings.value("textJotMarkDone").toString();
				if (!settings.value("textJotMarkScrapped").toString().isEmpty())
					textJotMarkScrapped = settings.value("textJotMarkScrapped").toString();
				if (!settings.value("colorJotCommentBg").isNull())
					colorJotCommentBg = settings.value("colorJotCommentBg").value<QColor>();
				if (!settings.value("colorJotCommentText").isNull())
					colorJotCommentText = settings.value("colorJotCommentText").value<QColor>();
				if (!settings.value("colorJotListTitleBg").isNull())
					colorJotListTitleBg = settings.value("colorJotListTitleBg").value<QColor>();
				if (!settings.value("colorJotListTitleText").isNull())
					colorJotListTitleText = settings.value("colorJotListTitleText").value<QColor>();
				if (!settings.value("colorJotMarkDoneBg").isNull())
					colorJotMarkDoneBg = settings.value("colorJotMarkDoneBg").value<QColor>();
				if (!settings.value("colorJotMarkDoneText").isNull())
					colorJotMarkDoneText = settings.value("colorJotMarkDoneText").value<QColor>();
				if (!settings.value("colorJotMarkScrappedBg").isNull())
					colorJotMarkScrappedBg = settings.value("colorJotMarkScrappedBg").value<QColor>();
				if (!settings.value("colorJotMarkScrappedText").isNull())
					colorJotMarkScrappedText = settings.value("colorJotMarkScrappedText").value<QColor>();
				settings.endGroup();
			}

			fileSetCurrent(filename);
			statusBar()->showMessage(tr("File loaded"), 2000);
			fileDirLastOpened = QFileInfo(filename).path();
		}
	}
}

bool CuteLittleNotesThemeCreator::fileSaveModifCheck()
{
	if (!themeModifiedUnsaved)
		return true;

	const QMessageBox::StandardButton ret
		= QMessageBox::warning(this, tr("Cute Little Notes"),
			tr("The document has been modified.\nDo you want to save your changes?"),
			QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

	switch (ret)
	{
	case QMessageBox::Save:
		return fileSaveOps();
	case QMessageBox::Cancel:
		return false;
	default:
		break;
	}

	return true;
}

bool CuteLittleNotesThemeCreator::fileSaveOps()
{
	if (fileCurrent.isEmpty())
	{
		return fileSaveAs();
	}
	else
	{
		return fileSave(fileCurrent);
	}
}

bool CuteLittleNotesThemeCreator::fileSave(const QString &filename)
{
	// Create folder for icons, copy CSS-referenced icons into the folder, edit style with new icon paths.
	{
		const QString dirName = QFileInfo(filename).baseName() + "_images";
		const QString dirPath = QFileInfo(filename).path() + "/" + dirName;
		qDebug() << dirPath;
		QDir dir(dirPath);
		if (!dir.exists())
			dir.mkpath(".");

		const std::string mainToolBarStyle = ui.mainToolBar->styleSheet().toStdString();
		QStringList toolbarIconsCssList;
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionNew{", "}", mainToolBarStyle)));
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionOpen{", "}", mainToolBarStyle)));
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionSave{", "}", mainToolBarStyle)));
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionComment{", "}", mainToolBarStyle)));
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionListTitle{", "}", mainToolBarStyle)));
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionMarkDone{", "}", mainToolBarStyle)));
		toolbarIconsCssList.append(QString::fromStdString(extractSubstring("QToolButton#toolbarButtonActionMarkScrapped{", "}", mainToolBarStyle)));
		
		std::string revisedStylesheet = ui.mainToolBar->styleSheet().toStdString();

		for (auto& toolbarIconCss : toolbarIconsCssList)
		{
			const QString toolbarButtonId = QString::fromStdString(extractSubstringInbetween("QToolButton#", "{", toolbarIconCss.toStdString()));
			const QString copyFromPath = QString::fromStdString(extractSubstringInbetween("url(", ")", toolbarIconCss.toStdString()));
			const QString copyToPath = dirPath + "/" + toolbarButtonId + ".png";
			qDebug() << "copyFromPath: " + copyFromPath;
			qDebug() << "copyToPath: " + copyToPath;

			if (QFile::exists(copyToPath) && (copyFromPath != copyToPath))
			{
				QFile(copyToPath).setPermissions(QFile::ReadOther | QFile::WriteOther);
				if (!QFile::remove(copyToPath))
					qDebug() << "File remove failed. File is probably in a location where permissions are strictly read-only.";
			}
			QFile::copy(copyFromPath, copyToPath);
			QFile(copyToPath).setPermissions(QFile::ReadOther | QFile::WriteOther);

			const QString replaceStrBegin = "#" + toolbarButtonId + "{  qproperty-icon: url(";
			revisedStylesheet = replaceSubstring(replaceStrBegin.toStdString(), ")", copyToPath.toStdString(), revisedStylesheet);
			qDebug() << QString::fromStdString(revisedStylesheet);
		}
		ui.mainToolBar->setStyleSheet(QString::fromStdString(revisedStylesheet));

		{
			const QString copyFromPath = QString::fromStdString(extractSubstringInbetween("url(", ")", ui.menuDropdown->styleSheet().toStdString()));
			const QString copyToPath = dirPath + "/menuIconCheckableIsChecked.png";
			if (QFile::exists(copyToPath) && (copyFromPath != copyToPath))
			{
				QFile(copyToPath).setPermissions(QFile::ReadOther | QFile::WriteOther);
				if (!QFile::remove(copyToPath))
					qDebug() << "File remove failed. File is probably in a location where permissions are strictly read-only.";
			}
			QFile::copy(copyFromPath, copyToPath);
			QFile(copyToPath).setPermissions(QFile::ReadOther | QFile::WriteOther);

			std::string revisedStylesheet = ui.menuDropdown->styleSheet().toStdString();
			revisedStylesheet = replaceSubstring("url(", ")", copyToPath.toStdString(), revisedStylesheet);

			qDebug() << QString::fromStdString(revisedStylesheet);
			ui.menuDropdown->setStyleSheet(QString::fromStdString(revisedStylesheet));
		}
	}

	// Write the QSS data to file.
	{
		std::ofstream fileWrite(filename.toStdString());
		QString textEditContents;
		textEditContents.append(ui.textEdit->styleSheet());
		textEditContents.append(ui.mainToolBar->styleSheet());
		textEditContents.append(ui.menuBar->styleSheet());
		textEditContents.append(ui.menuDropdown->styleSheet());
		textEditContents.append(ui.statusBar->styleSheet());
		textEditContents.replace("{", "\n{\n");
		textEditContents.replace("}", "}\n\n");
		textEditContents.replace(";", ";\n");
		if (fileWrite.is_open())
		{
			fileWrite << textEditContents.toStdString();
		}
		else
		{
			return false;
		}
		fileWrite.close();
	}

	// Using the name from the QSS file, save themeInfo data to file.
	{
		const QString fpath = QFileInfo(filename).path() + "/" + QFileInfo(filename).baseName() + "_themeInfo.ini";
		QSettings settings(fpath, QSettings::IniFormat);
		settings.beginGroup("ModInfo");
		settings.setValue("modType", "Theme");
		settings.setValue("creatorName", themeInfoCreatorName);
		settings.setValue("themeUniqueName", themeInfoThemeName);
		settings.setValue("versionNumber", themeInfoVersionNum);
		settings.endGroup();
	}

	// Using the name from the QSS file, save themeJot data to file.
	// Pertains to misc color/text settings for Jot operations.
	{
		const QString fpath = QFileInfo(filename).path() + "/" + QFileInfo(filename).baseName() + "_themeJot.ini";
		QSettings settings(fpath, QSettings::IniFormat);
		settings.beginGroup("JotSettings");
		settings.setValue("textJotMarkDone", textJotMarkDone);
		settings.setValue("textJotMarkScrapped", textJotMarkScrapped);
		settings.setValue("colorJotCommentBg", colorJotCommentBg.name());
		settings.setValue("colorJotCommentText", colorJotCommentText.name());
		settings.setValue("colorJotListTitleBg", colorJotListTitleBg.name());
		settings.setValue("colorJotListTitleText", colorJotListTitleText.name());
		settings.setValue("colorJotMarkDoneBg", colorJotMarkDoneBg.name());
		settings.setValue("colorJotMarkDoneText", colorJotMarkDoneText.name());
		settings.setValue("colorJotMarkScrappedBg", colorJotMarkScrappedBg.name());
		settings.setValue("colorJotMarkScrappedText", colorJotMarkScrappedText.name());
		settings.endGroup();
	}

	// Give a warning if there is no creator/theme name.
	if (ui.actionInfoNotSetWarning->isChecked())
	{
		if (themeInfoCreatorName.isEmpty() || themeInfoThemeName.isEmpty())
		{
			QMessageBox::warning(this, tr("Export Warning"), "Theme or Creator name is empty. Make sure to set these for the theme to work properly in Cute Little Notes.\n\nYou can disable this warning in the Set Theme Info menu.");
		}
	}

	fileSetCurrent(filename);
	statusBar()->showMessage(tr("File saved"), 2000);
	fileDirLastSaved = QFileInfo(filename).path();
	return true;
}

bool CuteLittleNotesThemeCreator::fileSaveAs()
{
	QFileDialog dialog(this, tr("Save As"), fileDirLastSaved, tr("QSS Files (*.qss)"));
	dialog.setWindowModality(Qt::WindowModal);
	dialog.setAcceptMode(QFileDialog::AcceptSave);
	if (dialog.exec() != QFileDialog::Accepted)
		return false;
	return fileSave(dialog.selectedFiles().first());
}

void CuteLittleNotesThemeCreator::setThemeInfoName(QString &themeInfoNameX, const QString nameX)
{
	bool ok;
	QString newName = QInputDialog::getText
	(
		this, 
		tr("Choose %1 Name").arg(nameX),
		tr("%1 Name:").arg(nameX), 
		QLineEdit::Normal, 
		themeInfoNameX,
		&ok, 
		Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint
	);
	if (ok && !newName.isEmpty())
	{
		themeInfoNameX = newName;
		fileDocumentModified();
	}
}

void CuteLittleNotesThemeCreator::setThemeInfoVersionNumber()
{
	bool ok;
	QString newNum = QInputDialog::getText
	(
		this,
		tr("Choose Version Number"),
		tr("Version Number:"),
		QLineEdit::Normal,
		QString::number(themeInfoVersionNum),
		&ok,
		Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint
	);
	if (ok && !newNum.isEmpty())
	{
		double newNumAsDouble;
		bool validDouble;
		newNumAsDouble = newNum.toDouble(&validDouble);
		if (validDouble)
		{
			themeInfoVersionNum = newNumAsDouble;
			fileDocumentModified();
			refreshStatusTips();
		}
	}
}

void CuteLittleNotesThemeCreator::setThemeMiscColor(QColor &color)
{
	QColor colorEdited = QColorDialog::getColor(color, this, "Choose Color");
	if (colorEdited.isValid())
	{
		color = colorEdited;
		fileDocumentModified();
	}
}

void CuteLittleNotesThemeCreator::setThemeMiscText(QString &text)
{
	bool ok;
	QString textEdited = QInputDialog::getText(this, tr("Set Text"), tr("Text:"), QLineEdit::Normal, text, &ok, Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
	if (ok && !textEdited.isEmpty())
	{
		text = textEdited;
		fileDocumentModified();
	}
}

void CuteLittleNotesThemeCreator::jotComment()
{
	bool ok;
	QString strToAdd = QInputDialog::getText(this, tr("Insert Comment"), tr("Comment:"), QLineEdit::Normal, "", &ok, Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

	if (ok && !strToAdd.isEmpty())
	{
		QTextCursor cursor(ui.textEdit->textCursor());
		cursor.beginEditBlock();
		ui.textEdit->insertPlainText(" ");
		ui.textEdit->insertHtml
		(
			"<span style=\"background-color:" + colorJotCommentBg.name() +
			"; color:" + colorJotCommentText.name() +
			";\">[" + strToAdd + "]</span> "
		);
		cursor.endEditBlock();
	}
}

void CuteLittleNotesThemeCreator::jotListTitle()
{
	bool ok;
	QString strToAdd = QInputDialog::getText(this, tr("Insert List Title"), tr("List Title:"), QLineEdit::Normal, "", &ok, Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);

	if (ok && !strToAdd.isEmpty())
	{
		QTextCursor cursor(ui.textEdit->textCursor());
		cursor.beginEditBlock();
		ui.textEdit->insertHtml
		(
			"<h2><span style=\"background-color:" + colorJotListTitleBg.name() +
			"; color:" + colorJotListTitleText.name() +
			"; font-weight: bold; text-transform: uppercase;\">" + strToAdd + "</span></h2><br />"
		);
		cursor.endEditBlock();
	}
}

void CuteLittleNotesThemeCreator::jotMarkDone()
{
	QTextCursor cursor(ui.textEdit->textCursor());
	cursor.beginEditBlock();
	ui.textEdit->insertPlainText(" ");
	ui.textEdit->insertHtml
	(
		"<span style=\"background-color:" + colorJotMarkDoneBg.name() +
		"; color:" + colorJotMarkDoneText.name() +
		";\">" + textJotMarkDone + "</span> "
	);
	cursor.endEditBlock();
}

void CuteLittleNotesThemeCreator::jotMarkScrapped()
{
	QTextCursor cursor(ui.textEdit->textCursor());
	cursor.beginEditBlock();
	ui.textEdit->insertPlainText(" ");
	ui.textEdit->insertHtml
	(
		"<span style=\"background-color:" + colorJotMarkScrappedBg.name() +
		"; color:" + colorJotMarkScrappedText.name() +
		";\">" + textJotMarkScrapped + "</span> "
	);
	cursor.endEditBlock();
}

void CuteLittleNotesThemeCreator::prefLoad()
{
	QSettings settings(appExecutablePath + "/preferences.ini", QSettings::IniFormat);

	settings.beginGroup("CreatorInfo");
	if (!settings.value("themeInfoCreatorName").toString().isEmpty())
		themeInfoCreatorName = settings.value("themeInfoCreatorName").toString();
	settings.endGroup();

	settings.beginGroup("Toggles");
	if (!settings.value("actionInfoNotSetWarning").isNull())
		ui.actionInfoNotSetWarning->setChecked(settings.value("actionInfoNotSetWarning").toBool());
	settings.endGroup();

	settings.beginGroup("FilePathMemory");
	if (!settings.value("fileDirLastOpened").toString().isEmpty())
		fileDirLastOpened = settings.value("fileDirLastOpened").toString();
	if (!settings.value("fileDirLastSaved").toString().isEmpty())
		fileDirLastSaved = settings.value("fileDirLastSaved").toString();
	settings.endGroup();
}

void CuteLittleNotesThemeCreator::prefSave()
{
	QSettings settings(appExecutablePath + "/preferences.ini", QSettings::IniFormat);

	settings.beginGroup("CreatorInfo");
	settings.setValue("themeInfoCreatorName", themeInfoCreatorName);
	settings.endGroup();

	settings.beginGroup("Toggles");
	settings.setValue("actionInfoNotSetWarning", ui.actionInfoNotSetWarning->isChecked());
	settings.endGroup();

	settings.beginGroup("FilePathMemory");
	settings.setValue("fileDirLastOpened", fileDirLastOpened);
	settings.setValue("fileDirLastSaved", fileDirLastSaved);
	settings.endGroup();
}