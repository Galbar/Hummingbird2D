#ifndef H2D_TRANSFORMATION_HPP
#define H2D_TRANSFORMATION_HPP

namespace h2d
{
class Transformation
{
public:
	Transformation():
	x(0.0),
	y(0.0),
	z(0.0),
	rotation(0.0),
	scale_x(1.0),
	scale_y(1.0)
	{}

	double x;
	double y;
	double z;
	double rotation;
	double scale_x;
	double scale_y;
};
}
#endif
