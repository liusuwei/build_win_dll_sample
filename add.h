#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NODLLEXPORT
__declspec(dllexport) int add(int, int);
#else
int add(int, int);
#endif

#ifdef __cplusplus
}
#endif