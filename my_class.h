class MyClass
{
private:
    int data = 5;
    int magnifier = 1;

public:
    MyClass();
    MyClass(int data);
    ~MyClass();

    void Add();

    void SetMagnifier(int magnifier);

    int GetData() const noexcept;

    int GetMagnifier() const noexcept;
};
