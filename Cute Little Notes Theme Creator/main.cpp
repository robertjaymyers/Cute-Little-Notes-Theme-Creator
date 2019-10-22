#include "CuteLittleNotesThemeCreator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/CuteLittleNotesThemeCreator/IconsBuiltIn/CuteLittleNotesThemeCreator_MainIcon.ico"));
	a.setAttribute(Qt::AA_DontShowIconsInMenus);
	CuteLittleNotesThemeCreator w;
	w.show();
	return a.exec();
}
