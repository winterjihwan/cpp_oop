class Shape {
public:
  virtual void get_x() = 0;
  virtual void get_y() = 0;
  virtual void get_z() = 0;
  virtual void get_height() = 0;
  virtual void get_width() = 0;
  virtual ~Shape() = default;
};
