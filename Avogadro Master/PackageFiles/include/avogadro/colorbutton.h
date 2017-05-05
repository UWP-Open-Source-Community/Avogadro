/**********************************************************************
  ColorButton - Button widget to display the current selected color
                and bring up the color picker when clicked

	Copyright (c) 2008-2009 Geoff Hutchison
	Copyright (c) 2008 Tim Vandermeersch
	Copyright (c) 2009 Marcus D. Hanwell

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.openmolecules.net/>

  Avogadro is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Avogadro is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
 **********************************************************************/

#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <avogadro/global.h>

#include <QAbstractButton>
#include <QColor>

namespace Avogadro {

  /**
   * @class ColorButton colorbutton.h <avogadro/colorbutton.h>
   * @author Geoffrey Hutchison
   * @brief A button to show the current color and bring up the QColorDialog.
   *
   * This class implements a QAbstractButton to display a colored rectangle.
   * When clicked by the user, it brings up a color picker to select a new
   * color.
   *
   * The widget has a default minimium size of 35x20 pixels.
   */

  class A_EXPORT ColorButton : public QAbstractButton
  {
    Q_OBJECT

  public:
    ColorButton(QWidget *parent = 0);
    explicit ColorButton(const QColor& initial, QWidget *parent = 0);

    /**
     *  Redraw the widget (i.e., refresh the colored rectange)
     */
    void paintEvent(QPaintEvent *);

    /**
     * @param color the new color to be used
     */
    void setColor(const QColor& color);

    /**
     * @param custom title for color choice dialog
     */
    void setDialogTitle(const QString title = "");

    /**
     * @return the current color
     */
    QColor color() const;

  Q_SIGNALS:
    /**
     *  emit any time the color is changed, either by a user or by setColor()
     */
    void colorChanged(QColor);

  public Q_SLOTS:
    /**
     * Call for a change in the current color
     */
    void changeColor();

  protected:
    /**
     * Generic event handler, currently defaults to calling parent class
     * (included for future compatibility)
     */
    bool event(QEvent *e);

    QColor m_color; //!< The current color
    QString m_title;//!< The current dialog title
  };

} // end namespace Avogadro

#endif
