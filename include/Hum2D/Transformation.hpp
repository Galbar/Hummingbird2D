#ifndef H2D_TRANSFORMATION_HPP
#define H2D_TRANSFORMATION_HPP
namespace h2d
{
class Transformation
{
public:
    Transformation();

    double x;
    double y;
    double z;
    double rotation;
    double scale_x;
    double scale_y;
};
}
#endif
