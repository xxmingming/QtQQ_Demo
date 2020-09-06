#pragma once
#include <QProxyStyle>
#include <QPixmap>
#include <QSize>

//改变默认的部件风格
class CustomProxyStyle:public QProxyStyle
{
public:
	CustomProxyStyle(QObject *parent)
	{
		this->setParent(parent);
	}
	virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
		QPainter *painter, const QWidget *widget = 0) const {
		if (PE_FrameFocusRect == element)  //PE_FrameFocusRect:边框获取焦点
		{
			//去掉windows中部件默认的边框或虚线框，部件获取焦点时直接返回，不进行绘制
			return;
		}
		else {
			QProxyStyle::drawPrimitive(element, option, painter, widget);
		}
	}
};

class CommonUtils
{
public:
	CommonUtils();
	virtual ~CommonUtils();

public:
	static QPixmap getRoundImage(const QPixmap &src, QPixmap &mask, QSize &maskSize=QSize(0,0));
	static void loadStyleSheet(QWidget *widget, const QString &sheetName);
	static void setDefaultSkinColor(const QColor &color);
	static QColor getDefaultSkinColor();
};

