#include <QGLWidget>

class Double : QGLWidget
{
    Q_OBJECT

public:
    Double(QWidget *parent = 0);
    ~Double();

protected:
    void initializeGL();
    void paintEvent(QPaintEvent *event);
    void resizeGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);
};

void Double::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

