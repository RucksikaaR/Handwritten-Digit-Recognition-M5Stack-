#ifndef NEUTON_MODEL_MODEL_H
#define NEUTON_MODEL_MODEL_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Model info */
#define NEUTON_MODEL_HEADER_VERSION 3
#define NEUTON_MODEL_QLEVEL 8
#define NEUTON_MODEL_FLOAT_SUPPORT 1
#define NEUTON_MODEL_TASK_TYPE 0  // multiclass classification
#define NEUTON_MODEL_NEURONS_COUNT 49
#define NEUTON_MODEL_WEIGHTS_COUNT 299
#define NEUTON_MODEL_INPUTS_COUNT 255
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 1
#define NEUTON_MODEL_OUTPUTS_COUNT 9
#define NEUTON_MODEL_LOG_SCALE_OUTPUTS 0
#define NEUTON_MODEL_HAS_CLASSES_RATIO 0
#define NEUTON_MODEL_HAS_NEGPOS_RATIO 0

/* Preprocessing */
#define NEUTON_PREPROCESSING_ENABLED 0
#define NEUTON_DROP_ORIGINAL_FEATURES 0
#define NEUTON_BITMASK_ENABLED 1
#define NEUTON_INPUTS_IS_INTEGER 0
#define NEUTON_MODEL_SA_PRECISION 24

/* Types */
typedef float input_t;
typedef float extracted_feature_t;
typedef uint8_t coeff_t;
typedef int8_t weight_t;
typedef int32_t acc_signed_t;
typedef uint32_t acc_unsigned_t;
typedef uint8_t sources_size_t;
typedef uint16_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Limits */
static const input_t modelInputMin[] = { 0 };
static const input_t modelInputMax[] = { 89408 };

static const uint8_t modelUsedInputsMask[] = {
	0xff, 0xff, 0xff, 0xbd, 0x9f, 0xb9, 0xb7, 0xed, 0x7e, 0xdc, 0x09, 0x00,
	0x6e, 0x65, 0x68, 0x10, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* Structure */
static const weight_t modelWeights[] = {
	13, -117, 2, 54, 124, 99, 42, -105, 124, -80, -51, 122, 60, -16, 16, 94,
	-126, 6, 15, -85, -128, 25, -47, 115, -17, 125, 89, 116, -89, -45, -37,
	-5, 108, -41, -79, -23, -83, 46, -64, -33, 109, 26, 124, 26, -128, -2,
	-128, 124, -65, 124, -46, -128, 62, -11, -26, 60, -128, 84, -12, -122,
	-2, 83, 9, -91, -113, 30, 58, -128, -3, -128, 102, -84, 27, -128, 51, -128,
	121, -82, 126, -128, -66, -89, -42, 8, 125, -128, -54, -56, -128, 111,
	-13, -45, 28, -128, -62, -128, 105, 59, 123, -113, 123, -22, -126, 77,
	4, -21, -34, 120, 12, -128, -38, -128, -30, -103, 75, -49, 4, -78, 124,
	-18, 16, -37, -3, -65, -65, -128, -2, -128, -2, -109, 69, 117, 28, 44,
	-97, -105, 54, -123, -114, -29, 124, 121, 111, -113, -2, -117, 86, 0, -100,
	58, 123, -128, -128, -70, -58, 117, 43, 18, 28, -13, -27, -121, 108, -127,
	113, -5, -128, 124, -2, -128, 61, 61, -128, -81, -50, 18, 125, 27, -120,
	-128, -128, -17, 91, 57, -65, -55, -8, -39, 114, 121, -128, 41, -9, 122,
	-128, 58, -102, -128, -102, 54, 122, -39, 83, -40, -85, 113, -9, -86, -126,
	-128, -128, -80, 46, -22, -30, 50, -128, 91, 97, -50, -128, -128, -16,
	17, -92, -37, 56, 124, 30, 18, -49, -128, 15, -103, -128, -122, 8, -118,
	90, -110, -64, 124, 109, -128, -17, 12, -128, 111, 121, -50, -94, 125,
	-82, -128, 58, 35, -32, -3, -25, -78, -28, 8, -64, -53, -128, 96, 98, 32,
	125, -59, -128, -56, 125, 60, -74, 101, -128, 38, 91, 5, -91, 20, -128,
	34, 118, -125, 37, 111, 125, -111, -50, 49, -10, -101, -128, 114, 38, -45,
	-8 };

static const sources_size_t modelLinks[] = {
	3, 11, 28, 36, 55, 104, 255, 3, 9, 23, 34, 76, 255, 1, 5, 32, 34, 67, 255,
	0, 4, 5, 12, 13, 97, 255, 1, 34, 55, 59, 79, 255, 2, 14, 24, 35, 124, 255,
	1, 3, 10, 47, 58, 255, 3, 2, 45, 48, 102, 255, 5, 18, 22, 66, 83, 255,
	2, 7, 9, 19, 56, 109, 255, 19, 20, 26, 106, 115, 255, 5, 7, 21, 59, 154,
	255, 3, 10, 39, 49, 56, 255, 4, 36, 55, 70, 97, 255, 11, 27, 31, 48, 52,
	255, 3, 3, 4, 17, 18, 255, 34, 45, 48, 53, 75, 255, 4, 23, 45, 68, 134,
	255, 9, 11, 29, 43, 61, 255, 7, 9, 18, 47, 115, 255, 7, 11, 12, 74, 78,
	255, 15, 4, 34, 67, 106, 255, 1, 29, 44, 63, 101, 255, 13, 19, 33, 65,
	70, 118, 255, 10, 22, 26, 40, 98, 255, 0, 10, 21, 24, 255, 1, 2, 3, 4,
	16, 20, 255, 0, 1, 2, 3, 17, 255, 17, 0, 11, 48, 80, 255, 3, 4, 27, 50,
	62, 255, 0, 1, 2, 3, 80, 255, 3, 12, 12, 47, 68, 255, 5, 14, 31, 255, 18,
	19, 21, 28, 52, 110, 255, 1, 11, 26, 28, 33, 255, 0, 1, 2, 3, 99, 255,
	8, 17, 22, 35, 255, 3, 17, 8, 59, 79, 255, 2, 9, 18, 19, 23, 37, 255, 0,
	1, 2, 3, 6, 22, 255, 4, 13, 27, 29, 39, 255, 0, 1, 3, 4, 4, 255, 16, 18,
	35, 40, 69, 255, 6, 15, 30, 41, 42, 255, 18, 31, 11, 16, 117, 255, 3, 12,
	44, 255, 0, 1, 2, 3, 23, 26, 41, 255, 31, 35, 3, 15, 58, 83, 255, 7, 16,
	20, 46, 47, 255 };

static const weights_size_t modelIntLinksBoundaries[] = {
	0, 7, 14, 20, 26, 32, 39, 45, 51, 57, 63, 71, 75, 81, 87, 94, 99, 106,
	113, 120, 126, 130, 136, 142, 148, 158, 165, 171, 173, 181, 188, 192, 199,
	203, 212, 217, 223, 226, 236, 241, 249, 254, 258, 267, 270, 277, 285, 288,
	298 };
static const weights_size_t modelExtLinksBoundaries[] = {
	7, 13, 19, 26, 32, 38, 44, 50, 56, 63, 69, 75, 81, 87, 93, 99, 105, 111,
	117, 123, 129, 135, 141, 148, 154, 159, 166, 172, 178, 184, 190, 196, 200,
	207, 213, 219, 224, 230, 237, 244, 250, 256, 262, 268, 274, 278, 286, 293,
	299 };

static const coeff_t modelFuncCoeffs[] = {
	86, 107, 142, 111, 115, 75, 81, 153, 135, 157, 140, 40, 158, 153, 157,
	158, 144, 157, 145, 154, 158, 69, 160, 160, 103, 72, 88, 158, 156, 157,
	157, 158, 54, 71, 46, 160, 78, 141, 107, 1, 141, 158, 82, 56, 160, 55,
	80, 157, 83 };
static const uint8_t modelFuncTypes[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0 };

static const neurons_size_t modelOutputNeurons[] = {
	25, 34, 38, 45, 40, 32, 43, 48, 36 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

