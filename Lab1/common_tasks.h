#ifndef ADS_COMMON_TASK_H
#define ADS_COMMON_TASK_H

int* get_n();

float* get_array(const int* n);

float** get_matrix(const int* m, const int* n);

void delete_matrix(float** matrix, const int* m);

float** get_square_matrix(const int* n);

#endif