#ifndef WAVEFRONT_H_
#define WAVEFRONT_H_

#ifdef __cplusplus
extern "C" {
#endif

void read_objf();
void read_matf(char** _name, float* _ka, float* _kd, float* _ks, float* _ns, float* _d);

#ifdef __cplusplus
}
#endif
#endif //WAVEFRONT_H_