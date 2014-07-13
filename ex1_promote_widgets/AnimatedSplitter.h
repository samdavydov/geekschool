#pragma once

#include <QtWidgets/QSplitter>
#include <QtCore/QEasingCurve>

QT_FORWARD_DECLARE_CLASS(QPropertyAnimation)

class AnimatedSplitter : public QSplitter
{
	Q_OBJECT

    Q_PROPERTY(int splitterHandlePosition READ handlePosition WRITE setHandleAt)

public:
	AnimatedSplitter(
		QWidget* parent, 
        int animationDuration = 500,
		const QEasingCurve& curve = QEasingCurve::InOutQuad
		);

public:
    int handlePosition() const;
    int animationDuration();

public slots:
    void moveHandleAt(int position);
    void setHandleAt(int position);

    void setAnimationDuration(int msec);

signals:
    void animationFinished();

private:
    QPropertyAnimation* m_animation;
    int m_splitterHandlePosition;
};
