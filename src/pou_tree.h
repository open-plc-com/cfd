/*
	Name:			pou_tree.h
	Purpose:		Open-PLC Tools
	Author:			www.open-plc.com
	Created:		20YY/MM
	Modified by:
	RCS-ID:
	Copyright:		(c) Open-PLC
	Licence:		The MIT License (MIT)
*/


#ifndef __POU_TREE__
#define __POU_TREE__

#include "msg.h"

//#define NN_0			0
//#define LVL_0			0
//#define NAME_0		""
//#define RU_NAME_0		""
//#define COMMENT_0		""
//#define RU_COMMENT_0	""
//#define POU_INOUT_0	""

// --- Standard function blocks ---

#define NN_0101         101
#define LVL_0101        1
#define NAME_0101       "Standard function blocks"
#define RU_NAME_0101    "Стандартные функциональные блоки"

#define NN_0102         102
#define LVL_0102        2
#define NAME_0102       "SR"
#define COMMENT_0102    "SR trigger with turn-on priority."
#define RU_COMMENT_0102 "SR-триггер с приоритетом включения."
#define POU_INOUT_0102  "(BOOL:S1, BOOL:R) => (BOOL:Q1)"

#define NN_0103         103
#define LVL_0103        2
#define NAME_0103       "RS"
#define COMMENT_0103    "RS trigger with shutdown priority."
#define RU_COMMENT_0103 "RS-триггер с приоритетом выключения."
#define POU_INOUT_0103  "(BOOL:S, BOOL:R1) => (BOOL:Q1)"

#define NN_0104         104
#define LVL_0104        2
#define NAME_0104       "SEMA"
#define COMMENT_0104    "A semaphore provides a software synchronization mechanism to ensure exclusive access to certain resources."
#define RU_COMMENT_0104 "Семафор предоставляет собой программный механизм синхронизации для обеспечения исключительного доступа к определенным ресурсам."
#define POU_INOUT_0104  "(BOOL:CLAIM, BOOL:RELEASE) => (BOOL:BUSY)"

#define NN_0105         105
#define LVL_0105        2
#define NAME_0105       "R_TRIG"
#define COMMENT_0105    "Rising edge detector. A single pulse is generated at the output if a rising edge is detected."
#define RU_COMMENT_0105 "Детектор нарастающего фронта. На выходе формируется одиночный импульс, если обнаружен нарастающий фронт."
#define POU_INOUT_0105  "(BOOL:CLK) => (BOOL:Q)"

#define NN_0106         106
#define LVL_0106        2
#define NAME_0106       "F_TRIG"
#define COMMENT_0106    "Falling edge detector. A single pulse is generated at the output if a falling edge is detected."
#define RU_COMMENT_0106 "Детектор падающего фронта. На выходе формируется одиночный импульс, если обнаружен падающий фронт."
#define POU_INOUT_0106  "(BOOL:CLK) => (BOOL:Q)"

#define NN_0107         107
#define LVL_0107        2
#define NAME_0107       "CTU"
#define COMMENT_0107    "An incremental counter can be used when it is necessary to signal that the counter has reached its maximum value."
#define RU_COMMENT_0107 "Инкрементный счетчик может использоваться, когда необходимо сигнализировать, что счетчик достиг максимального значения."
#define POU_INOUT_0107  "(BOOL:CU, BOOL:R, INT:PV) => (BOOL:Q, INT:CV)"

#define NN_0108         108
#define LVL_0108        2
#define NAME_0108       "CTU_DINT"
#define POU_INOUT_0108  "(BOOL:CU, BOOL:R, DINT:PV) => (BOOL:Q, DINT:CV)"

#define NN_0109         109
#define LVL_0109        2
#define NAME_0109       "CTU_LINT"
#define POU_INOUT_0109  "(BOOL:CU, BOOL:R, LINT:PV) => (BOOL:Q, LINT:CV)"

#define NN_0110         110
#define LVL_0110        2
#define NAME_0110       "CTU_UDINT"
#define POU_INOUT_0110  "(BOOL:CU, BOOL:R, UDINT:PV) => (BOOL:Q, UDINT:CV)"

#define NN_0111         111
#define LVL_0111        2
#define NAME_0111       "CTU_ULINT"
#define POU_INOUT_0111  "(BOOL:CU, BOOL:R, ULINT:PV) => (BOOL:Q, ULINT:CV)"

#define NN_0112         112
#define LVL_0112        2
#define NAME_0112       "CTD"
#define COMMENT_0112    "A decremental counter can be used when it is necessary to signal that the counter has reached zero from an initial setpoint."
#define RU_COMMENT_0112 "Декрементный счетчик может использоваться, когда необходимо сигнализировать, что счетчик достиг нулевого значения с исходного заданного значения."
#define POU_INOUT_0112  "(BOOL:CD, BOOL:LD, INT:PV) => (BOOL:Q, INT:CV)"

#define NN_0113         113
#define LVL_0113        2
#define NAME_0113       "CTD_DINT"
#define POU_INOUT_0113  "(BOOL:CD, BOOL:LD, DINT:PV) => (BOOL:Q, DINT:CV)"

#define NN_0114         114
#define LVL_0114        2
#define NAME_0114       "CTD_LINT"
#define POU_INOUT_0114  "(BOOL:CD, BOOL:LD, LINT:PV) => (BOOL:Q, LINT:CV)"

#define NN_0115         115
#define LVL_0115        2
#define NAME_0115       "CTD_UDINT"
#define POU_INOUT_0115  "(BOOL:CD, BOOL:LD, UDINT:PV) => (BOOL:Q, UDINT:CV)"

#define NN_0116         116
#define LVL_0116        2
#define NAME_0116       "CTD_ULINT"
#define POU_INOUT_0116  "(BOOL:CD, BOOL:LD, ULINT:PV) => (BOOL:Q, ULINT:CV)"

#define NN_0117         117
#define LVL_0117        2
#define NAME_0117       "CTUD"
#define COMMENT_0117    "The increment/decrement counter has two inputs CU and CD. It can be used to count up on one input and count down on the other."
#define RU_COMMENT_0117 "Инкрементный/декрементный счетчик имеет два входа CU и CD. Он может использоваться для счета вверх по одному входу и для счета низ по другому."
#define POU_INOUT_0117  "(BOOL:CU, BOOL:CD, BOOL:R, BOOL:LD, INT:PV) => (BOOL:QU, BOOL:QD, INT:CV, R_TRIG:CD_T, R_TRIG:CU_T)"

#define NN_0118         118
#define LVL_0118        2
#define NAME_0118       "CTUD_DINT"
#define POU_INOUT_0118  "(BOOL:CU, BOOL:CD, BOOL:R, BOOL:LD, DINT:PV) => (BOOL:QU, BOOL:QD, DINT:CV, R_TRIG:CD_T, R_TRIG:CU_T)"

#define NN_0119         119
#define LVL_0119        2
#define NAME_0119       "CTUD_LINT"
#define POU_INOUT_0119  "(BOOL:CU, BOOL:CD, BOOL:R, BOOL:LD, LINT:PV) => (BOOL:QU, BOOL:QD, LINT:CV, R_TRIG:CD_T, R_TRIG:CU_T)"

#define NN_0120         120
#define LVL_0120        2
#define NAME_0120       "CTUD_UDINT"
#define POU_INOUT_0120  "(BOOL:CU, BOOL:CD, BOOL:R, BOOL:LD, UDINT:PV) => (BOOL:QU, BOOL:QD, UDINT:CV, R_TRIG:CD_T, R_TRIG:CU_T)"

#define NN_0121         121
#define LVL_0121        2
#define NAME_0121       "CTUD_ULINT"
#define POU_INOUT_0121  "(BOOL:CU, BOOL:CD, BOOL:R, BOOL:LD, ULINT:PV) => (BOOL:QU, BOOL:QD, ULINT:CV, R_TRIG:CD_T, R_TRIG:CU_T)"

#define NN_0122         122
#define LVL_0122        2
#define NAME_0122       "TP"
#define COMMENT_0122    "Pulse generator. The function block is used to generate output pulses of a specified duration."
#define RU_COMMENT_0122 "Генератор импульсов. Функциональный блок используется для генерации выходных импульсов заданной длительности."
#define POU_INOUT_0122  "(BOOL:IN, TIME:PT) => (BOOL:Q, TIME:ET)"

#define NN_0123         123
#define LVL_0123        2
#define NAME_0123       "TON"
#define POU_INOUT_0123  "(BOOL:IN, TIME:PT) => (BOOL:Q, TIME:ET)"

#define NN_0124         124
#define LVL_0124        2
#define NAME_0124       "TOF"
#define POU_INOUT_0124  "(BOOL:IN, TIME:PT) => (BOOL:Q, TIME:ET)"

// --- Additional function blocks ---

#define NN_0201         201
#define LVL_0201        1
#define NAME_0201       "Additional function blocks"
#define RU_NAME_0201    "Дополнительные функциональные блоки"

#define NN_0202         202
#define LVL_0202        2
#define NAME_0202       "RTC"
#define COMMENT_0202    "The real time clock is used to obtain timestamps, installation date and time of day in reports, alarms, etc."
#define RU_COMMENT_0202 "Часы реального времени используется для получения меток времени, установки даты и времени дня в отчетах, сообщениях об авариях и пр."
#define POU_INOUT_0202  "(BOOL:IN, DT:PDT) => (BOOL:Q, DT:CDT)"

#define NN_0203         203
#define LVL_0203        2
#define NAME_0203       "INTEGRAL"
#define COMMENT_0203    "The function block integrates the input value XIN over time."
#define RU_COMMENT_0203 "Функциональный блок интегрирует входное значение XIN во времени."
#define POU_INOUT_0203  "(BOOL:RUN, BOOL:R1, REAL:XIN, REAL:X0, TIME:CYCLE) => (BOOL:Q, REAL:XOUT)"

#define NN_0204         204
#define LVL_0204        2
#define NAME_0204       "DERIVATIVE"
#define COMMENT_0204    "The function block generates an output signal XOUT proportional to the rate of change of the input signal XIN."
#define RU_COMMENT_0204 "Функциональный блок формирует выход XOUT пропорционально частоте изменения входа XIN."
#define POU_INOUT_0204  "(BOOL:RUN, REAL:XIN, TIME:CYCLE) => (REAL:XOUT)"

#define NN_0205         205
#define LVL_0205        2
#define NAME_0205       "PID"
#define COMMENT_0205    "PID (Proportional Integral Differential) FB is a classic controller used in closed loop systems."
#define RU_COMMENT_0205 "ПИД (Пропорциональный Интегральный Дифференциальный) ФБ - классический регулятор, используемый в системах с обратной связью."
#define POU_INOUT_0205  "(BOOL:AUTO, REAL:PV, REAL:SP, REAL:X0, REAL:KP, REAL:TR, REAL:TD, TIME:CYCLE) => (REAL:XOUT)"

#define NN_0206         206
#define LVL_0206        2
#define NAME_0206       "RAMP"
#define COMMENT_0206    "Signal rate limiter. The function block is written according to the example given in the standard."
#define RU_COMMENT_0206 "Ограничитель скорости изменения сигнала. Функциональный блок написан согласно примеру, приведенному в стандарте."
#define POU_INOUT_0206  "(BOOL:RUN, REAL:X0, REAL:X1, TIME:TR, TIME:CYCLE) => (BOOL:BUSY, REAL:XOUT)"

#define NN_0207         207
#define LVL_0207        2
#define NAME_0207       "HYSTERESIS"
#define COMMENT_0207    "The functional block generates a discrete output with hysteresis depending on the difference between two real inputs XIN1 and XIN2."
#define RU_COMMENT_0207 "Функциональный блок формирует дискретный выход с гистерезисом в зависимости от разницы двух вещественных входов XIN1 и XIN2."
#define POU_INOUT_0207  "(REAL:XIN1, REAL:XIN2, REAL:EPS) => (BOOL:Q)"

// --- 3 Types Conversion ---

#define NN_0301			301
#define LVL_0301		1
#define NAME_0301		"Types Conversion"
#define RU_NAME_0301	"Преобразование типов"

// --- 4 Mathematical functions ---

#define NN_0401			401
#define LVL_0401		1
#define NAME_0401		"Mathematical functions"
#define RU_NAME_0401	"Математические функции"

#define NN_0402			402
#define LVL_0402		2
#define NAME_0402		"ABS"
#define COMMENT_0402	"Absolute number"
#define RU_COMMENT_0402	"Абсолютный номер"
#define POU_INOUT_0402	"(ANY_NUM:IN) => (ANY_NUM:OUT)"

#define NN_0403			403
#define LVL_0403		2
#define NAME_0403		"SQRT"
#define COMMENT_0403	"Square root"
#define RU_COMMENT_0403	"Квадратный корень"
#define POU_INOUT_0403	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0404			404
#define LVL_0404		2
#define NAME_0404		"LN"
#define COMMENT_0404	"Natural logarithm"
#define RU_COMMENT_0404	"Натуральный логарифм"
#define POU_INOUT_0404	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0405			405
#define LVL_0405		2
#define NAME_0405		"LOG"
#define COMMENT_0405	"Decimal logarithm"
#define RU_COMMENT_0405	"Десятичный логарифм"
#define POU_INOUT_0405	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0406			406
#define LVL_0406		2
#define NAME_0406		"EXP"
#define COMMENT_0406	"Take the exponent"
#define RU_COMMENT_0406	"Взятие экспоненты"
#define POU_INOUT_0406	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0407			407
#define LVL_0407		2
#define NAME_0407		"SIN"
#define COMMENT_0407	"Sinus"
#define RU_COMMENT_0407	"Синус"
#define POU_INOUT_0407	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0408			408
#define LVL_0408		2
#define NAME_0408		"COS"
#define COMMENT_0408	"Cosine"
#define RU_COMMENT_0408	"Косинус"
#define POU_INOUT_0408	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0409			409
#define LVL_0409		2
#define NAME_0409		"TAN"
#define COMMENT_0409	"Tangent"
#define RU_COMMENT_0409	"Тангенс"
#define POU_INOUT_0409	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0410			410
#define LVL_0410		2
#define NAME_0410		"ASIN"
#define COMMENT_0410	"Arcsine"
#define RU_COMMENT_0410	"Арксинус"
#define POU_INOUT_0410	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0411			411
#define LVL_0411		2
#define NAME_0411		"ACOS"
#define COMMENT_0411	"Arc cosine"
#define RU_COMMENT_0411	"Арккосинус"
#define POU_INOUT_0411	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

#define NN_0412			412
#define LVL_0412		2
#define NAME_0412		"ATAN"
#define COMMENT_0412	"Arctangent"
#define RU_COMMENT_0412	"Арктангенс"
#define POU_INOUT_0412	"(ANY_REAL:IN) => (ANY_REAL:OUT)"

// --- 5 Mathematics ---

#define NN_0501			501
#define LVL_0501		1
#define NAME_0501		"Mathematics"
#define RU_NAME_0501	"Математика"

#define NN_0502			502
#define LVL_0502		2
#define NAME_0502		"ADD"
#define COMMENT_0502	"Addition"
#define RU_COMMENT_0502	"Сложение"
#define POU_INOUT_0502	"(ANY_NUM:IN1, ANY_NUM:IN2) => (ANY_NUM:OUT)"

#define NN_0503			503
#define LVL_0503		2
#define NAME_0503		"MUL"
#define COMMENT_0503	"Multiplication"
#define RU_COMMENT_0503	"Умножение"
#define POU_INOUT_0503	"(ANY_NUM:IN1, ANY_NUM:IN2) => (ANY_NUM:OUT)"

#define NN_0504			504
#define LVL_0504		2
#define NAME_0504		"SUB"
#define COMMENT_0504	"Subtraction"
#define RU_COMMENT_0504	"Вычитание"
#define POU_INOUT_0504	"(ANY_NUM:IN1, ANY_NUM:IN2) => (ANY_NUM:OUT)"

#define NN_0505			505
#define LVL_0505		2
#define NAME_0505		"DIV"
#define COMMENT_0505	"Division"
#define RU_COMMENT_0505	"Деление"
#define POU_INOUT_0505	"(ANY_NUM:IN1, ANY_NUM:IN2) => (ANY_NUM:OUT)"

#define NN_0506			506
#define LVL_0506		2
#define NAME_0506		"MOD"
#define COMMENT_0506	"Remainder of the division"
#define RU_COMMENT_0506	"Остаток от деления (modulo)"
#define POU_INOUT_0506	"(ANY_INT:IN1, ANY_INT:IN2) => (ANY_INT:OUT)"

#define NN_0507			507
#define LVL_0507		2
#define NAME_0507		"EXPT"
#define COMMENT_0507	"Exponent"
#define RU_COMMENT_0507	"Экспонента"
#define POU_INOUT_0507	"(ANY_REAL:IN1, ANY_NUM:IN2) => (ANY_REAL:OUT)"

#define NN_0508			508
#define LVL_0508		2
#define NAME_0508		"MOVE"
#define COMMENT_0508	"Appropriation"
#define RU_COMMENT_0508	"Присвоение"
#define POU_INOUT_0508	"(ANY:IN) => (ANY:OUT)"

// --- 6 Time ---

#define NN_0601			601
#define LVL_0601		1
#define NAME_0601		"Time"
#define RU_NAME_0601	"Время"

// --- 7 Shear operations ---

#define NN_0701			701
#define LVL_0701		1
#define NAME_0701		"Shear operations"
#define RU_NAME_0701	"Сдвиговые операции"

#define NN_0702			702
#define LVL_0702		2
#define NAME_0702		"SHL"
#define COMMENT_0702	"Shift left"
#define RU_COMMENT_0702	"Сдвиг влево"
#define POU_INOUT_0702	"(ANY_BIT:IN, ANY_INT:N) => (ANY_BIT:OUT)"

#define NN_0703			703
#define LVL_0703		2
#define NAME_0703		"SHR"
#define COMMENT_0703	"Shift right"
#define RU_COMMENT_0703	"Сдвиг вправо"
#define POU_INOUT_0703	"(ANY_BIT:IN, ANY_INT:N) => (ANY_BIT:OUT)"

#define NN_0704			704
#define LVL_0704		2
#define NAME_0704		"ROR"
#define COMMENT_0704	"Cyclic shift right"
#define RU_COMMENT_0704	"Циклический сдвиг вправо"
#define POU_INOUT_0704	"(ANY_NBIT:IN, ANY_INT:N) => (ANY_NBIT:OUT)"

#define NN_0705			705
#define LVL_0705		2
#define NAME_0705		"ROL"
#define COMMENT_0705	"Cyclic shift left"
#define RU_COMMENT_0705	"Циклический сдвиг влево"
#define POU_INOUT_0705	"(ANY_NBIT:IN, ANY_INT:N) => (ANY_NBIT:OUT"

// --- 8 Bit operations ---

#define NN_0801			801
#define LVL_0801		1
#define NAME_0801		"Bit operations"
#define RU_NAME_0801	"Битовые операции"

#define NN_0802			802
#define LVL_0802		2
#define NAME_0802		"AND"
#define COMMENT_0802	"Bit AND"
#define RU_COMMENT_0802	"Битовое И"
#define POU_INOUT_0802	"(ANY_BIT:IN1, ANY_BIT:IN2) => (ANY_BIT:OUT)"

#define NN_0803			803
#define LVL_0803		2
#define NAME_0803		"OR"
#define COMMENT_0803	"Bit OR"
#define RU_COMMENT_0803	"Битовое ИЛИ"
#define POU_INOUT_0803	"(ANY_BIT:IN1, ANY_BIT:IN2) => (ANY_BIT:OUT)"

#define NN_0804			804
#define LVL_0804		2
#define NAME_0804		"XOR"
#define COMMENT_0804	"Exclusive OR"
#define RU_COMMENT_0804	"Исключающее ИЛИ"
#define POU_INOUT_0804	"(ANY_BIT:IN1, ANY_BIT:IN2) => (ANY_BIT:OUT)"

#define NN_0805			805
#define LVL_0805		2
#define NAME_0805		"NOT"
#define COMMENT_0805	"Bitwise NOT"
#define RU_COMMENT_0805	"Битовое НЕ"
#define POU_INOUT_0805	"(ANY_BIT:IN) => (ANY_BIT:OUT)"

// --- 9 Choice operations ---

#define NN_0901			901
#define LVL_0901		1
#define NAME_0901		"Choice"
#define RU_NAME_0901	"Выбор"

#define NN_0902			902
#define LVL_0902		2
#define NAME_0902		"SEL"
#define COMMENT_0902	"Binary choice (1 or 2)"
#define RU_COMMENT_0902	"Бинарный выбор (1 или 2)"
#define POU_INOUT_0902	"(BOOL:G, ANY:IN0, ANY:IN1) => (ANY:OUT)"

#define NN_0903			903
#define LVL_0903		2
#define NAME_0903		"MAX"
#define COMMENT_0903	"Maximum"
#define RU_COMMENT_0903	"Максимум"
#define POU_INOUT_0903	"(ANY:IN1, ANY:IN2) => (ANY:OUT)"

#define NN_0904			904
#define LVL_0904		2
#define NAME_0904		"MIN"
#define COMMENT_0904	"Minimum"
#define RU_COMMENT_0904	"Минимум"
#define POU_INOUT_0904	"(ANY:IN1, ANY:IN2) => (ANY:OUT)"

#define NN_0905			905
#define LVL_0905			2
#define NAME_0905		"LIMIT"
#define COMMENT_0905		"Limitation"
#define RU_COMMENT_0905	"Ограничение"
#define POU_INOUT_0905	"(ANY:MN, ANY:IN, ANY:MX) => (ANY:OUT)"

#define NN_0906			906
#define LVL_0906			2
#define NAME_0906		"MUX"
#define COMMENT_0906		"Multiplexer (1 in N)"
#define RU_COMMENT_0906	"Мультиплексор (1 в N)"
#define POU_INOUT_0906	"(ANY_INT:K, ANY:IN0, ANY:IN1) => (ANY:OUT)"

// --- 10 Comparison operations ---

#define NN_1001			1001
#define LVL_1001		1
#define NAME_1001		"Comparison"
#define RU_NAME_1001	"Сравнение"

// --- 11 String operations ---

#define NN_1101			1101
#define LVL_1101		1
#define NAME_1101		"String operations"
#define RU_NAME_1101	"Строковые операции"

/*

//#define NN_0			0
//#define LVL_0			2
//#define NAME_0		""
//#define RU_NAME_0		""
//#define COMMENT_0		""
//#define RU_COMMENT_0	""
//#define POU_INOUT_0	""

// --- Types Conversion ---------------------------------------------------

//#define NN_0301			301
//#define LVL_0301		1
//#define NAME_0301		"Types Conversion"
//#define RU_NAME_0301	"Преобразование типов"
//#define COMMENT_0301	""
//#define POU_INOUT_0301	""


// --- Time ---

#define NN_0601			601
#define LVL_0601		1
#define NAME_0601		"Time"
#define RU_NAME_0601	"Время"
#define COMMENT_0601	""
#define POU_INOUT_0601	""

// --- Comparison ---

#define NN_1001			1001
#define LVL_1001		1
#define NAME_1001		"Comparison"
#define RU_NAME_1001	"Сравнение"
#define COMMENT_1001	""
#define POU_INOUT_1001	""

// --- String operations ---

#define NN_1101			1101
#define LVL_1101		1
#define NAME_1101		"String operations"
#define RU_NAME_1101	"Строковые операции"
#define COMMENT_1101	""
#define POU_INOUT_1101	""

*/

// --- User POU ---------------------------------------------------------------

#define NN_10001		10001
#define LVL_10001		1
#define NAME_10001		"User POU"
#define COMMENT_10001	""
#define POU_INOUT_10001	""

#endif // __POU_TREE__