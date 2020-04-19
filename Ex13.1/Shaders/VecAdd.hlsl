struct Data
{
	float3 v1;
};

StructuredBuffer<Data> gInputA : register(t0);
RWStructuredBuffer<float> gOutput : register(u0);

// 연습문제 13.1
[numthreads(64, 1, 1)]
void CS(int3 dtid : SV_DispatchThreadID)
{
	gOutput[dtid.x] = sqrt(gInputA[dtid.x].v1.x * gInputA[dtid.x].v1.x +
		gInputA[dtid.x].v1.y * gInputA[dtid.x].v1.y +
		gInputA[dtid.x].v1.z * gInputA[dtid.x].v1.z);
}
