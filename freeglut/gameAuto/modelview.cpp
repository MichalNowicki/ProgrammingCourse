// Zapisanie aktualnej macierzy
glPushMatrix();

// Przesunięcie auta według ostatniej pozycji
glTranslated(auto->translacja[0], auto->translacja[1], auto->translacja[2]);

// Obrót auta według ostatniej pozycji
glRotated(auto->rotacja[0], 1.0, 0.0, 0.0);
glRotated(auto->rotacja[1], 0.0, 1.0, 0.0);
glRotated(auto->rotacja[2], 0.0, 0.0, 1.0);

// Wykonanie ruchu do przodu w układzie auta
glTranslated(0.0, 0.1, 0.0);

// Pobranie aktualnej pozycji i orientacji auta jako macierzy:
// 		/ r11 r12 r13 t1 \
// 		| r21 r22 r23 t2 |
// 		| r31 r32 r33 t3 |
// 		\ 0    0     0   1 /
double modelViewMatrix[16];
glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);

// Ustawienie aktualnej pozycji auta (elementy liczone kolumnami)
auto->UstawPozycje(modelViewMatrix[12], modelViewMatrix[13], 0.0);

// Powrót do układu początkowego
glPopMatrix();