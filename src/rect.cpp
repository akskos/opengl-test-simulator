#include "rect.h"

Rect::Rect(
	glm::vec3 point1,
	glm::vec3 point2,
	glm::vec3 point3,
	glm::vec3 point4) {

    // init vertex data
    GLfloat vertex_data[6 * 3];
    vertex_data[0] = point1.x;
    vertex_data[1] = point1.y;
    vertex_data[2] = point1.z;
    vertex_data[3] = point2.x;
    vertex_data[4] = point2.y;
    vertex_data[5] = point2.z;
    vertex_data[6] = point3.x;
    vertex_data[7] = point3.y;
    vertex_data[8] = point3.z;
    vertex_data[9] = point1.x;
    vertex_data[10] = point1.y;
    vertex_data[11] = point1.z;
    vertex_data[12] = point3.x;
    vertex_data[13] = point3.y;
    vertex_data[14] = point3.z;
    vertex_data[15] = point4.x;
    vertex_data[16] = point4.y;
    vertex_data[17] = point4.z;

    // generate and init vertex buffer
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
	    GL_ARRAY_BUFFER,
	    sizeof(vertex_data), 
	    vertex_data,
	    GL_STATIC_DRAW
    );

    // init color data
    GLfloat color_data[] = {
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f
    };
    
    // generate and init color buffer
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(
	    GL_ARRAY_BUFFER,
	    sizeof(color_data), 
	    color_data,
	    GL_STATIC_DRAW
    );
}

void Rect::setColor(glm::vec3 color) {
    GLfloat color_data[] = {
	color.x, color.y, color.z,
	color.x, color.y, color.z,
	color.x, color.y, color.z,
	color.x, color.y, color.z,
	color.x, color.y, color.z,
	color.x, color.y, color.z
    };
    
    // generate and init color buffer
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(
	    GL_ARRAY_BUFFER,
	    sizeof(color_data), 
	    color_data,
	    GL_STATIC_DRAW
    );
}

void Rect::render() {
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
}
