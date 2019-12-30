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
