# SimpleMathLibrary
Simple Math Library for Game Development.

It has 4 classes:
- vec2
- vec3
- vec4
- mat4

It was created to use in C++ with OpenGL in 2D Apps!

You can use lookAt mat4 functions to create cameras in OpenGL!

There are orthographic and perspective functions for Projection Matrices!

How to use:

math::vec2 vector(0.0f, 0.0f);

math::vec2 vector2(1.0f, 5.0f);

math::vec2 result = vector + vector2;

std::cout << result.PrintData() << '\n';

Matrices:
math::mat4 mat1 = math::mat4();
math::vec2 pos = math::vec2(1.0f, 0.0f);

mat1 = math::translate(pos);

