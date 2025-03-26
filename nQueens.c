#include"nQueens.h"

void printMatrix(mat* m, int ns) {
	printf("%d)\n", ns);
	for (int r = 0; r < m->rows; r++) {
		for (int c = 0; c < m->rows; c++) {
			if (m->data[r * m->cols + c] == 2) {
				printf("0 ");
			}
			else {
				printf("%d ", m->data[r * m->cols + c]);
			}
		}
		printf("\n");
	}

	printf("\n\n");
	return;
}

void calcMatrix(mat* m, int rr, int cc) {
	//0) free cell
	//1) queen
	//2) dangerous cell

	for (int r = 0; r < m->rows; r++) {
		for (int c = 0; c < m->cols; c++) {
			if (((c == cc) && (r != rr)) || ((r == rr) && (c != cc)) || ((r + c == rr + cc) && (r != rr)) || ((r - c == rr - cc) && (r != rr))) {
				if (m->data[r * m->cols + c] == 0) {
					m->data[r * m->cols + c] = 2;
				}
			}
		}
	}

	return;
}

void resetMatrix(mat* m) {
	for (int r = 0; r < m->rows; r++) {
		for (int c = 0; c < m->cols; c++) {
			if (m->data[r * m->cols + c] == 2) {
				m->data[r * m->cols + c] = 0;
			}
		}
	}

	for (int r = 0; r < m->rows; r++) {
		for (int c = 0; c < m->cols; c++) {
			if (m->data[r * m->cols + c] == 1) {
				calcMatrix(m, r, c);
			}
		}
	}

	return;
}

void nQueensRec(mat* m, int r, int c, int n, int* ns) {
	//default case
	if (n == m->rows) {
		*ns += 1;
		printMatrix(m, *ns);

		return;
	}

	for (r; r < m->rows; r++) {
		for (c; c < m->cols; c++) {
			if (m->data[r * m->cols + c] == 0) {

				m->data[r * m->cols + c] = 1;
				calcMatrix(m, r, c);

				nQueensRec(m, r, c + 1, n + 1, ns);

				m->data[r * m->cols + c] = 0;
				resetMatrix(m);

			}

		}
		c = 0;
	}

	return;
}

void nQueens(int l) {

	mat* m = calloc(1, sizeof(mat));
	m->rows = l;
	m->cols = l;
	int m_size = l * l;
	m->data = realloc(m->data, m_size * sizeof(int));
	for (int i = 0; i < m_size; i++) {
		m->data[i] = 0;
	}

	int ns = 0;
	nQueensRec(m, 0, 0, 0, &ns);

	free(m);

	return;
}
