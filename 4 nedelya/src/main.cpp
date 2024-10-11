#include "utils.h"
#include "camera.h"

int main()
{
    write_image(Camera(400, 2.0, 1.0, 16.0 / 9.0, vec3(0, 0, 0)));
}