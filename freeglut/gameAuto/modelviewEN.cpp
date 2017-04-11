// Save the current matrix
glPushMatrix();

// Move the auto to the last position
glTranslated(auto->translation[0], auto->translation[1], 0.0);

// Rotate the auto according to the last rotation
glRotated(auto->rotation, 0.0, 0.0, 1.0);

// Move the car forward
glTranslated(0.0, 0.1, 0.0);

// Get the current position as translation and rotation:
// 		/ r11 r12 r13 t1 \
// 		| r21 r22 r23 t2 |
// 		| r31 r32 r33 t3 |
// 		\ 0    0     0   1 /
double modelViewMatrix[16];
glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);

// Set the current position of the car (numbering by columns)
auto->setPosition(modelViewMatrix[12], modelViewMatrix[13], 0.0);

// We go back to the original coordinate system 
glPopMatrix();