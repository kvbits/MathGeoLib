#include "../src/MathGeoLib.h"
#include "TestRunner.h"
#include "../src/Math/SSEMath.h"

MATH_BEGIN_NAMESPACE

namespace TestData
{

float *PosFloatArray()
{
	LCG lcg;
	static float *arr;
	if (!arr)
	{
		arr = AlignedNew<float>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = lcg.Float(0.f, 100000.f);
	}
	return arr;
}

Quat *QuatArray()
{
	LCG lcg;
	static Quat *arr;
	if (!arr)
	{
		arr = AlignedNew<Quat>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = Quat::RandomRotation(lcg);
	}
	return arr;
}

float *FloatArray()
{
	LCG lcg;
	static float *arr;
	if (!arr)
	{
		arr = AlignedNew<float>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = lcg.Float(-10.f, 10.f);
	}
	return arr;
}

float4x4 *MatrixArray()
{
	LCG lcg;
	static float4x4 *arr;
	if (!arr)
	{
		arr = AlignedNew<float4x4>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = float4x4::RandomGeneral(lcg, -10.f, 10.f);
	}
	return arr;
}

float4x4 *MatrixArray2()
{
	LCG lcg;
	static float4x4 *arr;
	if (!arr)
	{
		arr = AlignedNew<float4x4>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = float4x4::RandomGeneral(lcg, -10.f, 10.f);
	}
	return arr;
}

float4x4 *TransposedMatrixArray()
{
	static float4x4 *arr;
	if (!arr)
	{
		arr = AlignedNew<float4x4>(testrunner_numItersPerTest);
		float4x4 *m = MatrixArray();
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = m[i].Transposed();
	}
	return arr;
}

float2 *Float2Array()
{
	LCG lcg;
	static float2 *arr;
	if (!arr)
	{
		arr = AlignedNew<float2>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = float2::RandomBox(lcg, -10.f, 10.f);
	}
	return arr;
}

float4 *VectorArray()
{
	LCG lcg;
	static float4 *arr;
	if (!arr)
	{
		arr = AlignedNew<float4>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = float4::RandomGeneral(lcg, -10.f, 10.f);
	}
	return arr;
}

float4 *VectorArray2()
{
	LCG lcg;
	static float4 *arr;
	if (!arr)
	{
		arr = AlignedNew<float4>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = float4::RandomGeneral(lcg, -10.f, 10.f);
	}
	return arr;
}

float4 *VectorArray3()
{
	LCG lcg;
	static float4 *arr;
	if (!arr)
	{
		arr = AlignedNew<float4>(testrunner_numItersPerTest);
		for(int i = 0; i < testrunner_numItersPerTest; ++i)
			arr[i] = float4::RandomGeneral(lcg, -10.f, 10.f);
	}
	return arr;
}

class FreeTestData
{
public:
	~FreeTestData()
	{
		AlignedFree(FloatArray());
		AlignedFree(PosFloatArray());
		AlignedFree(MatrixArray());
		AlignedFree(MatrixArray2());
		AlignedFree(Float2Array());
		AlignedFree(VectorArray());
		AlignedFree(VectorArray2());
		AlignedFree(VectorArray3());
		AlignedFree(TransposedMatrixArray());
		AlignedFree(QuatArray());
	}
};

// At app exit time, this causes all test data arrays to be freed.
FreeTestData testDataDeleter;

} // ~namespace TestData

MATH_END_NAMESPACE