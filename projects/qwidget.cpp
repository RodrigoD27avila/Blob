class MyWidget;

class MyWidget
{
public:
    MyWidget(int parent = 0);
    ~MyWidget();
};

MyWidget::MyWidget(int parent)
{
}

MyWidget::~MyWidget()
{
}

int main()
{
    MyWidget *foo = new MyWidget();
    delete foo;
    return 0;
}


