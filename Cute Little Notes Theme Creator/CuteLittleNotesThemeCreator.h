/*
This file is part of Cute Little Notes Theme Creator.
	Cute Little Notes Theme Creator is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	Cute Little Notes Theme Creator is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with Cute Little Notes Theme Creator.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CuteLittleNotesThemeCreator.h"

class CuteLittleNotesThemeCreator : public QMainWindow
{
	Q_OBJECT

public:
	CuteLittleNotesThemeCreator(QWidget *parent = Q_NULLPTR);
	void closeEvent(QCloseEvent *event);

private:
	Ui::CuteLittleNotesThemeCreatorClass ui;

	bool themeModifiedUnsaved = false;

	const QString appExecutablePath = QCoreApplication::applicationDirPath();
	QString fileDirLastOpened = appExecutablePath;
	QString fileDirLastSaved = appExecutablePath;
	QString fileCurrent;

	const QString winTitleProgramName = "Cute Little Notes Theme Creator";
	const QString winTitlePlaceholder = "[*]";
	const QString winTitleUntitled = "Untitled Theme";
	QString initTextEditContents;

	QString themeInfoCreatorName;
	QString themeInfoThemeName;
	double themeInfoVersionNum = 1.0;

	const QString actionSetCreatorName_statusTip = "Creator Name: %1";
	const QString actionSetThemeName_statusTip = "Theme Name: %1";
	const QString actionSetVersionNumber_statusTip = "Version Number defaults to 1.0 | Current Version Number is %1";


	const QString themePropertyStr_bgColor = "Background Color";
	const QString themePropertyStr_textColor = "Text Color";
	const QString themePropertyStr_borderColor = "Border Color";
	const QString themePropertyStr_separatorColor = "Separator Color";
	const QString themePropertyStr_menuItemBgColor = "Background Color (Menu Item)";
	const QString themePropertyStr_menuItemCheckedBgColor = "Background Color (Menu Item Checked)";
	const QString themePropertyStr_hoverBgColorMenu = "Hover Background Color (Menu)";
	const QString themePropertyStr_hoverTextColorMenu = "Hover Text Color (Menu)";
	const QString themePropertyStr_hoverBorderColorMenu = "Hover Border Color (Menu)";
	const QString themePropertyStr_hoverBgColorToolBar = "Hover Background Color (ToolBar)";
	const QString themePropertyStr_hoverBorderColorToolBar = "Hover Border Color (ToolBar)";
	const QString themePropertyStr_image = "Checked Option Image";
	const QString themePropertyStr_iconToolBarNew = "ToolBar Icon: New";
	const QString themePropertyStr_iconToolBarOpen = "ToolBar Icon: Open";
	const QString themePropertyStr_iconToolBarSave = "ToolBar Icon: Save";
	const QString themePropertyStr_iconToolBarComment = "ToolBar Icon: Comment";
	const QString themePropertyStr_iconToolBarListTitle = "ToolBar Icon: List Title";
	const QString themePropertyStr_iconToolBarMarkDone = "ToolBar Icon: Mark Done";
	const QString themePropertyStr_iconToolBarMarkScrapped = "ToolBar Icon: Mark Scrapped";
	const QString themePropertyStr_scrollBarBgColor = "Scroll Bar Background Color";

	const QString themeObjStr_textEdit = "textEdit";
	const QString themeObjStr_mainToolBar = "mainToolBar";
	const QString themeObjStr_menuBar = "menuBar";
	const QString themeObjStr_menuDropdown = "menuDropdown";
	const QString themeObjStr_statusBar = "statusBar";

	std::map<QString, QStringList> themeCssMap =
	{
		{themeObjStr_textEdit, { themePropertyStr_bgColor, themePropertyStr_textColor, themePropertyStr_borderColor, themePropertyStr_scrollBarBgColor }},
		{themeObjStr_mainToolBar, { themePropertyStr_bgColor, themePropertyStr_borderColor, themePropertyStr_separatorColor, themePropertyStr_hoverBgColorToolBar, themePropertyStr_hoverBorderColorToolBar, themePropertyStr_iconToolBarNew, themePropertyStr_iconToolBarOpen, themePropertyStr_iconToolBarSave, themePropertyStr_iconToolBarComment, themePropertyStr_iconToolBarListTitle, themePropertyStr_iconToolBarMarkDone, themePropertyStr_iconToolBarMarkScrapped }},
		{themeObjStr_menuBar, { themePropertyStr_bgColor, themePropertyStr_textColor, themePropertyStr_borderColor, themePropertyStr_hoverBgColorMenu, themePropertyStr_hoverTextColorMenu, themePropertyStr_hoverBorderColorMenu }},
		{themeObjStr_menuDropdown, { themePropertyStr_bgColor, themePropertyStr_textColor, themePropertyStr_borderColor, themePropertyStr_separatorColor, themePropertyStr_menuItemBgColor, themePropertyStr_menuItemCheckedBgColor, themePropertyStr_hoverBgColorMenu, themePropertyStr_hoverTextColorMenu, themePropertyStr_image }},
		{themeObjStr_statusBar, { themePropertyStr_bgColor, themePropertyStr_textColor }},
	};

	std::map<QString, QStringList>::iterator themeCssMapIterator;

	/*std::map<QString, QString> themePropertyMap = 
	{
		{themePropertyStr_bgColor, "  background-color: %1;"},
		{themePropertyStr_textColor, "  color: %1;"},
		{themePropertyStr_borderColor, "  border-color: %1;"},
	};*/

	std::map<QString, QString> themePropertyMap =
	{
		{themePropertyStr_bgColor, "  background-color: "},
		{themePropertyStr_textColor, "  color: "},
		{themePropertyStr_borderColor, "  border-color: "},
		{themePropertyStr_separatorColor, "::separator{  background-color: "},
		{themePropertyStr_menuItemBgColor, "::item{  background-color: "},
		{themePropertyStr_menuItemCheckedBgColor, "::indicator:non-exclusive:checked{  background-color: "},
		{themePropertyStr_hoverBgColorMenu, "::item:selected{  background-color: "},
		{themePropertyStr_hoverTextColorMenu, "::item:selected{  color: "},
		{themePropertyStr_hoverBorderColorMenu, "::item:selected{  border-color: "},
		{themePropertyStr_hoverBgColorToolBar, ":hover{  background-color: "},
		{themePropertyStr_hoverBorderColorToolBar, ":hover{  border-color: "},
		{themePropertyStr_image, "url("},
		{themePropertyStr_iconToolBarNew, "#toolbarButtonActionNew{  qproperty-icon: url("},
		{themePropertyStr_iconToolBarOpen, "#toolbarButtonActionOpen{  qproperty-icon: url("},
		{themePropertyStr_iconToolBarSave, "#toolbarButtonActionSave{  qproperty-icon: url("},
		{themePropertyStr_iconToolBarComment, "#toolbarButtonActionComment{  qproperty-icon: url("},
		{themePropertyStr_iconToolBarListTitle, "#toolbarButtonActionListTitle{  qproperty-icon: url("},
		{themePropertyStr_iconToolBarMarkDone, "#toolbarButtonActionMarkDone{  qproperty-icon: url("},
		{themePropertyStr_iconToolBarMarkScrapped, "#toolbarButtonActionMarkScrapped{  qproperty-icon: url("},
		{themePropertyStr_scrollBarBgColor, "QScrollBar{  background-color: "},
	};

	std::map<QString, QString>::iterator themePropertyMapIterator;

	QString textJotMarkDone = "DONE";
	QString textJotMarkScrapped = "SCRAPPED";
	QColor colorJotCommentBg = QColor(255, 180, 255, 255);
	QColor colorJotCommentText = QColor(0, 0, 0, 255);
	QColor colorJotListTitleBg = QColor(229, 229, 229, 255);
	QColor colorJotListTitleText = QColor(0, 0, 0, 255);
	QColor colorJotMarkDoneBg = QColor(93, 206, 224, 255);
	QColor colorJotMarkDoneText = QColor(0, 0, 0, 255);
	QColor colorJotMarkScrappedBg = QColor(214, 136, 126, 255);
	QColor colorJotMarkScrappedText = QColor(0, 0, 0, 255);

	/*struct themeMiscPrefs
	{
		QString textJotMarkDone = "DONE";
		QString textJotMarkScrapped = "SCRAPPED";
		QColor colorTextEditorBackground = QColor(255, 255, 255, 200);
		QColor colorTextEditorText = QColor(0, 0, 0, 200);
		QColor colorJotComment = QColor(219, 219, 219, 255);
		QColor colorJotListTitleBg = QColor(229, 229, 229, 255);
		QColor colorJotListTitleText = QColor(25, 25, 25, 255);
		QColor colorJotMarkDone = QColor(93, 206, 224, 255);
		QColor colorJotMarkScrapped = QColor(214, 136, 126, 255);
	};
	const themeMiscPrefs themeMiscPrefsList[1] = 
	{
		{
			"DONE",
			"SCRAPPED",
			QColor(255, 255, 255, 200),
			QColor(0, 0, 0, 200),
			QColor(219, 219, 219, 255),
			QColor(229, 229, 229, 255),
			QColor(25, 25, 25, 255),
			QColor(93, 206, 224, 255),
			QColor(214, 136, 126, 255)
		},
	};*/

	const QString textEditStyleSheetDefault =
		"QTextEdit{  border-color: #F2F2F2;  border-style: inset;  border-width: 1px;  background-color: #FFFFFF;  color: #000000;}"
		"QScrollBar{  background-color: #F0F0F0;}"
		;

	const QString mainToolBarStyleSheetDefault =
		"QToolBar{  background-color: #F0F0F0;  border-width: 1px 0px 1px 1px;  border-style: outset;  border-color: #B9B9B9;}"
		"QToolBar::separator{  background-color: #D3D3D3;  width: 1px;  height: 1px;  margin: 3px 3px 3px 2px;}"
		"QToolButton:hover{  background-color: #FFB4FF;  border-width: 1px;  border-style: solid;}"
		"QToolButton:hover{  border-color: #000000;}"
		"QToolButton#toolbarButtonActionNew{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-new.png);}"
		"QToolButton#toolbarButtonActionOpen{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-open.png);}"
		"QToolButton#toolbarButtonActionSave{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-save.png);}"
		"QToolButton#toolbarButtonActionComment{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-comment.png);}"
		"QToolButton#toolbarButtonActionListTitle{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-list-title.png);}"
		"QToolButton#toolbarButtonActionMarkDone{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-mark-done.png);}"
		"QToolButton#toolbarButtonActionMarkScrapped{  qproperty-icon: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-mark-scrapped.png);}"
		;

	const QString menuBarStyleSheetDefault =
		"QMenuBar{  background-color: #FFFFFF;  color: #000000;  border-bottom-width: 1px;  border-bottom-style: solid;  border-color: #F2F2F2;}"
		"QMenuBar::item:selected{  background-color: #FFB4FF;  border-width: 1px;  border-style: solid;}"
		"QMenuBar::item:selected{  color: #000000;}"
		"QMenuBar::item:selected{  border-color: #000000;}"
		;

	const QString dropdownMenuStyleSheetDefault =
		"QMenu{  background-color: #F0F0F0;  color: #000000;  border-color: #CCCCCC;  border-width: 1px;  border-style: solid;}"
		"QMenu::separator{  background-color: #D7D7D7;  width: 1px;  height: 1px;  margin: 3px 0px 3px 12px;}"
		"QMenu::item{  background-color: #F0F0F0;  margin: 2px;  padding: 2px 20px 2px 40px;  border: 1px solid transparent;}"
		"QMenu::item:selected{  background-color: #FFB4FF;}"
		"QMenu::item:selected{  color: #000000;}"
		"QMenu::indicator:non-exclusive:checked{  image: url(:/CuteLittleNotesThemeCreator/IconsBuiltIn/menu-icon-checkbox-is-checked-elephant.png);}"
		"QMenu::indicator:non-exclusive:checked{  background-color: #FFB4FF;}"
		;

	const QString statusBarStyleSheetDefault =
		"QStatusBar{  background-color: #FFFFFF;  color: #000000;}"
		;

	void debugMsgCssModified(const QString &objName, const QString &objStylesheet, const QString modifType);
	std::string extractSubstring(const std::string strBegin, const std::string strEnd, const std::string &strExtractFrom);
	std::string extractSubstringInbetween(const std::string strBegin, const std::string strEnd, const std::string &strExtractFrom);
	std::string replaceSubstring(const std::string strBegin, const std::string strEnd, const std::string strMid, const std::string strStylesheet);
	void refreshStatusTips();
	void setStyleSheetToDefault();

private slots:
	QString dialogChooseThemeProperty(const QString &objName, const QString &objStylesheet);
	void statusBarInit();
	void fileDocumentModified();
	void fileSetCurrent(const QString &filename);
	void fileNew();
	void fileOpen();
	bool fileSaveModifCheck();
	bool fileSaveOps();
	bool fileSave(const QString &filename);
	bool fileSaveAs();
	void setThemeInfoName(QString &themeInfoNameX, const QString nameX);
	void setThemeInfoVersionNumber();
	void setThemeMiscColor(QColor &color);
	void setThemeMiscText(QString &text);
	void jotComment();
	void jotListTitle();
	void jotMarkDone();
	void jotMarkScrapped();
	void prefLoad();
	void prefSave();
};
