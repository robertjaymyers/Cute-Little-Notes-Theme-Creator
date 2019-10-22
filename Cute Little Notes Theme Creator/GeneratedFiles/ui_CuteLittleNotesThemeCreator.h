/********************************************************************************
** Form generated from reading UI file 'CuteLittleNotesThemeCreator.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTELITTLENOTESTHEMECREATOR_H
#define UI_CUTELITTLENOTESTHEMECREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CuteLittleNotesThemeCreatorClass
{
public:
    QAction *actionSaveAs;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionWordWrap;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionComment;
    QAction *actionMarkDone;
    QAction *actionMarkScrapped;
    QAction *actionEraseComments;
    QAction *actionStripFormatting;
    QAction *actionPasteStripFormatting;
    QAction *actionPastePlainText;
    QAction *actionExit;
    QAction *actionSetColorComment;
    QAction *actionSetColorMarkDone;
    QAction *actionSetColorMarkScrapped;
    QAction *actionSetColorTextEditorBackground;
    QAction *actionSetColorTextEditorText;
    QAction *actionSetTextMarkDone;
    QAction *actionSetTextMarkScrapped;
    QAction *actionListTitle;
    QAction *actionPrefCommentSetColorBg;
    QAction *actionPrefCommentSetText;
    QAction *actionPrefMarkDoneSetColorBg;
    QAction *actionPrefMarkDoneSetText;
    QAction *actionPrefMarkScrappedSetColorBg;
    QAction *actionPrefMarkScrappedSetText;
    QAction *actionPrefListTitleSetColorBg;
    QAction *actionPrefListTitleSetColorText;
    QAction *actionPrefSaveManual;
    QAction *actionToolbarToggleVis;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionZoomReset;
    QAction *actionFormattingRemoveAll;
    QAction *actionSaveAsPlainText;
    QAction *actionPrefSetTheme;
    QAction *actionPrefToggleModding;
    QAction *actionMenu_Option_3;
    QAction *actionMenu_Option_4;
    QAction *actionMenu_Extend_1;
    QAction *actionMenu_Extend_2;
    QAction *actionMenu_Extend_3;
    QAction *actionMenu_Extend_4;
    QAction *actionMenu_Extend_5;
    QAction *actionMenu_Option_5;
    QAction *actionMenu_Option_6;
    QAction *actionMenu_Option_7;
    QAction *actionSetCreatorName;
    QAction *actionSetThemeName;
    QAction *actionSetVersionNumber;
    QAction *actionInfoNotSetWarning;
    QAction *actionPrefCommentSetColorText;
    QAction *actionPrefMarkDoneSetColorText;
    QAction *actionPrefMarkScrappedSetColorText;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QAction *action;
    QMenu *menuEdit;
    QMenu *menuJot;
    QMenu *menuList;
    QMenu *menuSetThemePreferencesMisc;
    QMenu *menuPrefComment;
    QMenu *menuPrefMarkDone;
    QMenu *menuPrefMarkScrapped;
    QMenu *menuPrefListTitle;
    QMenu *menuDropdown;
    QMenu *menuMenu_Option_1;
    QMenu *menuMenu_Option_2;
    QMenu *menuSetThemeInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CuteLittleNotesThemeCreatorClass)
    {
        if (CuteLittleNotesThemeCreatorClass->objectName().isEmpty())
            CuteLittleNotesThemeCreatorClass->setObjectName(QStringLiteral("CuteLittleNotesThemeCreatorClass"));
        CuteLittleNotesThemeCreatorClass->setEnabled(true);
        CuteLittleNotesThemeCreatorClass->resize(600, 400);
        actionSaveAs = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSave = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionOpen = new QAction(CuteLittleNotesThemeCreatorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionNew = new QAction(CuteLittleNotesThemeCreatorClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionWordWrap = new QAction(CuteLittleNotesThemeCreatorClass);
        actionWordWrap->setObjectName(QStringLiteral("actionWordWrap"));
        actionWordWrap->setCheckable(true);
        actionWordWrap->setChecked(true);
        actionUndo = new QAction(CuteLittleNotesThemeCreatorClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo->setCheckable(false);
        actionUndo->setEnabled(false);
        actionRedo = new QAction(CuteLittleNotesThemeCreatorClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionRedo->setEnabled(false);
        actionComment = new QAction(CuteLittleNotesThemeCreatorClass);
        actionComment->setObjectName(QStringLiteral("actionComment"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-comment.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComment->setIcon(icon3);
        actionMarkDone = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMarkDone->setObjectName(QStringLiteral("actionMarkDone"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-mark-done.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMarkDone->setIcon(icon4);
        actionMarkScrapped = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMarkScrapped->setObjectName(QStringLiteral("actionMarkScrapped"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-mark-scrapped.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMarkScrapped->setIcon(icon5);
        actionEraseComments = new QAction(CuteLittleNotesThemeCreatorClass);
        actionEraseComments->setObjectName(QStringLiteral("actionEraseComments"));
        actionStripFormatting = new QAction(CuteLittleNotesThemeCreatorClass);
        actionStripFormatting->setObjectName(QStringLiteral("actionStripFormatting"));
        actionPasteStripFormatting = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPasteStripFormatting->setObjectName(QStringLiteral("actionPasteStripFormatting"));
        actionPasteStripFormatting->setCheckable(true);
        actionPasteStripFormatting->setChecked(true);
        actionPastePlainText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPastePlainText->setObjectName(QStringLiteral("actionPastePlainText"));
        actionExit = new QAction(CuteLittleNotesThemeCreatorClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSetColorComment = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetColorComment->setObjectName(QStringLiteral("actionSetColorComment"));
        actionSetColorMarkDone = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetColorMarkDone->setObjectName(QStringLiteral("actionSetColorMarkDone"));
        actionSetColorMarkScrapped = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetColorMarkScrapped->setObjectName(QStringLiteral("actionSetColorMarkScrapped"));
        actionSetColorTextEditorBackground = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetColorTextEditorBackground->setObjectName(QStringLiteral("actionSetColorTextEditorBackground"));
        actionSetColorTextEditorText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetColorTextEditorText->setObjectName(QStringLiteral("actionSetColorTextEditorText"));
        actionSetTextMarkDone = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetTextMarkDone->setObjectName(QStringLiteral("actionSetTextMarkDone"));
        actionSetTextMarkScrapped = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetTextMarkScrapped->setObjectName(QStringLiteral("actionSetTextMarkScrapped"));
        actionListTitle = new QAction(CuteLittleNotesThemeCreatorClass);
        actionListTitle->setObjectName(QStringLiteral("actionListTitle"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/CuteLittleNotesThemeCreator/IconsBuiltIn/toolbar-icon-list-title.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionListTitle->setIcon(icon6);
        actionPrefCommentSetColorBg = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefCommentSetColorBg->setObjectName(QStringLiteral("actionPrefCommentSetColorBg"));
        actionPrefCommentSetText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefCommentSetText->setObjectName(QStringLiteral("actionPrefCommentSetText"));
        actionPrefMarkDoneSetColorBg = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefMarkDoneSetColorBg->setObjectName(QStringLiteral("actionPrefMarkDoneSetColorBg"));
        actionPrefMarkDoneSetText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefMarkDoneSetText->setObjectName(QStringLiteral("actionPrefMarkDoneSetText"));
        actionPrefMarkScrappedSetColorBg = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefMarkScrappedSetColorBg->setObjectName(QStringLiteral("actionPrefMarkScrappedSetColorBg"));
        actionPrefMarkScrappedSetText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefMarkScrappedSetText->setObjectName(QStringLiteral("actionPrefMarkScrappedSetText"));
        actionPrefListTitleSetColorBg = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefListTitleSetColorBg->setObjectName(QStringLiteral("actionPrefListTitleSetColorBg"));
        actionPrefListTitleSetColorText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefListTitleSetColorText->setObjectName(QStringLiteral("actionPrefListTitleSetColorText"));
        actionPrefSaveManual = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefSaveManual->setObjectName(QStringLiteral("actionPrefSaveManual"));
        actionToolbarToggleVis = new QAction(CuteLittleNotesThemeCreatorClass);
        actionToolbarToggleVis->setObjectName(QStringLiteral("actionToolbarToggleVis"));
        actionToolbarToggleVis->setCheckable(true);
        actionToolbarToggleVis->setChecked(true);
        actionZoomIn = new QAction(CuteLittleNotesThemeCreatorClass);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        actionZoomOut = new QAction(CuteLittleNotesThemeCreatorClass);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        actionZoomReset = new QAction(CuteLittleNotesThemeCreatorClass);
        actionZoomReset->setObjectName(QStringLiteral("actionZoomReset"));
        actionFormattingRemoveAll = new QAction(CuteLittleNotesThemeCreatorClass);
        actionFormattingRemoveAll->setObjectName(QStringLiteral("actionFormattingRemoveAll"));
        actionSaveAsPlainText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSaveAsPlainText->setObjectName(QStringLiteral("actionSaveAsPlainText"));
        actionPrefSetTheme = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefSetTheme->setObjectName(QStringLiteral("actionPrefSetTheme"));
        actionPrefToggleModding = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefToggleModding->setObjectName(QStringLiteral("actionPrefToggleModding"));
        actionPrefToggleModding->setCheckable(true);
        actionMenu_Option_3 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Option_3->setObjectName(QStringLiteral("actionMenu_Option_3"));
        actionMenu_Option_4 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Option_4->setObjectName(QStringLiteral("actionMenu_Option_4"));
        actionMenu_Extend_1 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Extend_1->setObjectName(QStringLiteral("actionMenu_Extend_1"));
        actionMenu_Extend_2 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Extend_2->setObjectName(QStringLiteral("actionMenu_Extend_2"));
        actionMenu_Extend_3 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Extend_3->setObjectName(QStringLiteral("actionMenu_Extend_3"));
        actionMenu_Extend_4 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Extend_4->setObjectName(QStringLiteral("actionMenu_Extend_4"));
        actionMenu_Extend_5 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Extend_5->setObjectName(QStringLiteral("actionMenu_Extend_5"));
        actionMenu_Option_5 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Option_5->setObjectName(QStringLiteral("actionMenu_Option_5"));
        actionMenu_Option_6 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Option_6->setObjectName(QStringLiteral("actionMenu_Option_6"));
        actionMenu_Option_6->setCheckable(true);
        actionMenu_Option_6->setChecked(true);
        actionMenu_Option_7 = new QAction(CuteLittleNotesThemeCreatorClass);
        actionMenu_Option_7->setObjectName(QStringLiteral("actionMenu_Option_7"));
        actionSetCreatorName = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetCreatorName->setObjectName(QStringLiteral("actionSetCreatorName"));
        actionSetThemeName = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetThemeName->setObjectName(QStringLiteral("actionSetThemeName"));
        actionSetVersionNumber = new QAction(CuteLittleNotesThemeCreatorClass);
        actionSetVersionNumber->setObjectName(QStringLiteral("actionSetVersionNumber"));
        actionInfoNotSetWarning = new QAction(CuteLittleNotesThemeCreatorClass);
        actionInfoNotSetWarning->setObjectName(QStringLiteral("actionInfoNotSetWarning"));
        actionInfoNotSetWarning->setCheckable(true);
        actionInfoNotSetWarning->setChecked(true);
        actionPrefCommentSetColorText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefCommentSetColorText->setObjectName(QStringLiteral("actionPrefCommentSetColorText"));
        actionPrefMarkDoneSetColorText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefMarkDoneSetColorText->setObjectName(QStringLiteral("actionPrefMarkDoneSetColorText"));
        actionPrefMarkScrappedSetColorText = new QAction(CuteLittleNotesThemeCreatorClass);
        actionPrefMarkScrappedSetColorText->setObjectName(QStringLiteral("actionPrefMarkScrappedSetColorText"));
        centralWidget = new QWidget(CuteLittleNotesThemeCreatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setPointSize(10);
        textEdit->setFont(font);
        textEdit->setStyleSheet(QStringLiteral(""));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setReadOnly(false);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        CuteLittleNotesThemeCreatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CuteLittleNotesThemeCreatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        action = new QAction(menuView);
        action->setObjectName(QStringLiteral("action"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuJot = new QMenu(menuBar);
        menuJot->setObjectName(QStringLiteral("menuJot"));
        menuList = new QMenu(menuJot);
        menuList->setObjectName(QStringLiteral("menuList"));
        menuSetThemePreferencesMisc = new QMenu(menuBar);
        menuSetThemePreferencesMisc->setObjectName(QStringLiteral("menuSetThemePreferencesMisc"));
        menuPrefComment = new QMenu(menuSetThemePreferencesMisc);
        menuPrefComment->setObjectName(QStringLiteral("menuPrefComment"));
        menuPrefMarkDone = new QMenu(menuSetThemePreferencesMisc);
        menuPrefMarkDone->setObjectName(QStringLiteral("menuPrefMarkDone"));
        menuPrefMarkScrapped = new QMenu(menuSetThemePreferencesMisc);
        menuPrefMarkScrapped->setObjectName(QStringLiteral("menuPrefMarkScrapped"));
        menuPrefListTitle = new QMenu(menuSetThemePreferencesMisc);
        menuPrefListTitle->setObjectName(QStringLiteral("menuPrefListTitle"));
        menuDropdown = new QMenu(menuBar);
        menuDropdown->setObjectName(QStringLiteral("menuDropdown"));
        menuMenu_Option_1 = new QMenu(menuDropdown);
        menuMenu_Option_1->setObjectName(QStringLiteral("menuMenu_Option_1"));
        menuMenu_Option_2 = new QMenu(menuDropdown);
        menuMenu_Option_2->setObjectName(QStringLiteral("menuMenu_Option_2"));
        menuSetThemeInfo = new QMenu(menuBar);
        menuSetThemeInfo->setObjectName(QStringLiteral("menuSetThemeInfo"));
        CuteLittleNotesThemeCreatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CuteLittleNotesThemeCreatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        mainToolBar->setMovable(false);
        mainToolBar->setOrientation(Qt::Horizontal);
        CuteLittleNotesThemeCreatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CuteLittleNotesThemeCreatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CuteLittleNotesThemeCreatorClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSetThemeInfo->menuAction());
        menuBar->addAction(menuJot->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSetThemePreferencesMisc->menuAction());
        menuBar->addAction(menuDropdown->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionWordWrap);
        menuView->addAction(actionToolbarToggleVis);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionPastePlainText);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFormattingRemoveAll);
        menuJot->addAction(actionComment);
        menuJot->addAction(actionListTitle);
        menuJot->addSeparator();
        menuJot->addAction(menuList->menuAction());
        menuList->addAction(actionMarkDone);
        menuList->addAction(actionMarkScrapped);
        menuSetThemePreferencesMisc->addAction(menuPrefComment->menuAction());
        menuSetThemePreferencesMisc->addAction(menuPrefListTitle->menuAction());
        menuSetThemePreferencesMisc->addSeparator();
        menuSetThemePreferencesMisc->addAction(menuPrefMarkDone->menuAction());
        menuSetThemePreferencesMisc->addAction(menuPrefMarkScrapped->menuAction());
        menuPrefComment->addAction(actionPrefCommentSetColorBg);
        menuPrefComment->addAction(actionPrefCommentSetColorText);
        menuPrefMarkDone->addAction(actionPrefMarkDoneSetColorBg);
        menuPrefMarkDone->addAction(actionPrefMarkDoneSetColorText);
        menuPrefMarkDone->addAction(actionPrefMarkDoneSetText);
        menuPrefMarkScrapped->addAction(actionPrefMarkScrappedSetColorBg);
        menuPrefMarkScrapped->addAction(actionPrefMarkScrappedSetColorText);
        menuPrefMarkScrapped->addAction(actionPrefMarkScrappedSetText);
        menuPrefListTitle->addAction(actionPrefListTitleSetColorBg);
        menuPrefListTitle->addAction(actionPrefListTitleSetColorText);
        menuDropdown->addAction(menuMenu_Option_1->menuAction());
        menuDropdown->addAction(menuMenu_Option_2->menuAction());
        menuDropdown->addSeparator();
        menuDropdown->addAction(actionMenu_Option_3);
        menuDropdown->addAction(actionMenu_Option_4);
        menuDropdown->addSeparator();
        menuDropdown->addAction(actionMenu_Option_5);
        menuDropdown->addAction(actionMenu_Option_6);
        menuDropdown->addSeparator();
        menuDropdown->addAction(actionMenu_Option_7);
        menuMenu_Option_1->addAction(actionMenu_Extend_1);
        menuMenu_Option_1->addAction(actionMenu_Extend_2);
        menuMenu_Option_2->addAction(actionMenu_Extend_3);
        menuMenu_Option_2->addAction(actionMenu_Extend_4);
        menuMenu_Option_2->addAction(actionMenu_Extend_5);
        menuSetThemeInfo->addAction(actionSetCreatorName);
        menuSetThemeInfo->addAction(actionSetThemeName);
        menuSetThemeInfo->addAction(actionSetVersionNumber);
        menuSetThemeInfo->addSeparator();
        menuSetThemeInfo->addAction(actionInfoNotSetWarning);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionComment);
        mainToolBar->addAction(actionListTitle);
        mainToolBar->addAction(actionMarkDone);
        mainToolBar->addAction(actionMarkScrapped);

        retranslateUi(CuteLittleNotesThemeCreatorClass);

        QMetaObject::connectSlotsByName(CuteLittleNotesThemeCreatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *CuteLittleNotesThemeCreatorClass)
    {
        CuteLittleNotesThemeCreatorClass->setWindowTitle(QString());
        actionSaveAs->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Save As...", nullptr));
        actionSave->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Save", nullptr));
        actionOpen->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Open...", nullptr));
        actionNew->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "New", nullptr));
        actionWordWrap->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Word Wrap", nullptr));
        actionUndo->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        actionComment->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Comment", nullptr));
        actionMarkDone->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Done", nullptr));
        actionMarkScrapped->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Scrapped", nullptr));
        actionEraseComments->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Erase Comments", nullptr));
        actionStripFormatting->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Strip Formatting from Selected Text", nullptr));
        actionPasteStripFormatting->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Paste Strips Formatting", nullptr));
        actionPastePlainText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Paste as Plain Text", nullptr));
        actionExit->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Exit", nullptr));
        actionSetColorComment->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Comment", nullptr));
        actionSetColorMarkDone->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Done", nullptr));
        actionSetColorMarkScrapped->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Scrapped", nullptr));
        actionSetColorTextEditorBackground->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Background", nullptr));
        actionSetColorTextEditorText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Text", nullptr));
        actionSetTextMarkDone->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Done", nullptr));
        actionSetTextMarkScrapped->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Scrapped", nullptr));
        actionListTitle->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "List Title", nullptr));
        actionPrefCommentSetColorBg->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Bg", nullptr));
        actionPrefCommentSetText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Text", nullptr));
        actionPrefMarkDoneSetColorBg->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Bg", nullptr));
        actionPrefMarkDoneSetText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Text", nullptr));
        actionPrefMarkScrappedSetColorBg->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Bg", nullptr));
        actionPrefMarkScrappedSetText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Text", nullptr));
        actionPrefListTitleSetColorBg->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Bg", nullptr));
        actionPrefListTitleSetColorText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Text", nullptr));
        actionPrefSaveManual->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Save Preferences", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPrefSaveManual->setToolTip(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Save Preferences", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPrefSaveManual->setStatusTip(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Preferences are saved automatically on exit, but you can also save them manually.", nullptr));
#endif // QT_NO_STATUSTIP
        actionToolbarToggleVis->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Toolbar", nullptr));
        actionZoomIn->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Zoom In", nullptr));
        actionZoomOut->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Zoom Out", nullptr));
        actionZoomReset->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Zoom Reset", nullptr));
        actionFormattingRemoveAll->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Remove Special Formatting", nullptr));
#ifndef QT_NO_STATUSTIP
        actionFormattingRemoveAll->setStatusTip(QApplication::translate("CuteLittleNotesThemeCreatorClass", "This will remove special formatting, such as text color or background color.", nullptr));
#endif // QT_NO_STATUSTIP
        actionSaveAsPlainText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Save As Plain Text", nullptr));
#ifndef QT_NO_STATUSTIP
        actionSaveAsPlainText->setStatusTip(QApplication::translate("CuteLittleNotesThemeCreatorClass", "This will save the file without special formatting, such as text color or background color.", nullptr));
#endif // QT_NO_STATUSTIP
        actionPrefSetTheme->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Theme", nullptr));
        actionPrefToggleModding->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Enable Modding", nullptr));
#ifndef QT_NO_STATUSTIP
        actionPrefToggleModding->setStatusTip(QApplication::translate("CuteLittleNotesThemeCreatorClass", "If enabled, the program will check the local Mods folder for content upon loading.", nullptr));
#endif // QT_NO_STATUSTIP
        actionMenu_Option_3->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Modify That", nullptr));
        actionMenu_Option_4->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Change This", nullptr));
        actionMenu_Extend_1->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Menu Extend 1", nullptr));
        actionMenu_Extend_2->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Menu Extend 2", nullptr));
        actionMenu_Extend_3->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Menu Extend 3", nullptr));
        actionMenu_Extend_4->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Menu Extend 4", nullptr));
        actionMenu_Extend_5->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Menu Extend 5", nullptr));
        actionMenu_Option_5->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Thing", nullptr));
        actionMenu_Option_6->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Sample Checkbox", nullptr));
        actionMenu_Option_7->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Save Stuff", nullptr));
        actionSetCreatorName->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Creator Name", nullptr));
        actionSetThemeName->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Theme Name", nullptr));
        actionSetVersionNumber->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Version Number", nullptr));
#ifndef QT_NO_STATUSTIP
        actionSetVersionNumber->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionInfoNotSetWarning->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Info Not Set Warning", nullptr));
        actionPrefCommentSetColorText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Text", nullptr));
        actionPrefMarkDoneSetColorText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Text", nullptr));
        actionPrefMarkScrappedSetColorText->setText(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Color Text", nullptr));
        textEdit->setHtml(QApplication::translate("CuteLittleNotesThemeCreatorClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This is a development version of Cute Little Notes, made for designing themes for the text editor program Cute Little Notes. This is NOT the text editor itself!</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Right-click on a place in the interface (for example, this box) to set available theme parameters for the click"
                        "ed place in the interface (ex: background color, text color).</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Save to export your theme. It's recommended that you save each theme in its own folder so that you can simply copy/paste that folder into your Cute Little Notes Mods folder when you're finished. This also helps with organization. Themes are saved as a QSS stylesheet file and also produce an images folder and ini file for mod info details, such as creator and theme name.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">See the co"
                        "mpanion Theme Editing Diagram image for a guide to what areas can be right-clicked on for editing.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Note that editing the menu called Dropdown Template will only edit that menu in Cute Little Notes Theme Creator, but will apply to all dropdown menus when the theme is applied in Cute Little Notes.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p sty"
                        "le=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-botto"
                        "m:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragra"
                        "ph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0"
                        "px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; m"
                        "argin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>"
                        "\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; m"
                        "argin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This is text placed far enough down to show a vertical scroll bar, so that you can check the styling of it.</p></body></html>", nullptr));
        menuFile->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "File", nullptr));
        menuView->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "View", nullptr));
        menuEdit->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Edit", nullptr));
        menuJot->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Jot", nullptr));
        menuList->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "List Item", nullptr));
        menuSetThemePreferencesMisc->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Theme Jot", nullptr));
        menuPrefComment->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Comment", nullptr));
        menuPrefMarkDone->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Done", nullptr));
        menuPrefMarkScrapped->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Mark Scrapped", nullptr));
        menuPrefListTitle->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "List Title", nullptr));
        menuDropdown->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Dropdown Template", nullptr));
        menuMenu_Option_1->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set List Item", nullptr));
        menuMenu_Option_2->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set List Item Alt", nullptr));
        menuSetThemeInfo->setTitle(QApplication::translate("CuteLittleNotesThemeCreatorClass", "Set Theme Info", nullptr));
        mainToolBar->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class CuteLittleNotesThemeCreatorClass: public Ui_CuteLittleNotesThemeCreatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTELITTLENOTESTHEMECREATOR_H
