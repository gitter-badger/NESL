#include <Windows.h>
#include "../NESL/LogicGraph.h"
#include <iostream>



#include "../ESLConsole/Declare.h" //导入原游戏声明

struct EGravity { int32_t g; }; //重力
ENTITY_STATE(EGravity, Vec);


auto Logic_Gravity(EVelocity& vel, const EGravity& gravity) //重力改变速度
{
	vel.y -= gravity.g;
}

auto Init(ESL::Entity e, ESpawner&,
	ESL::State<EGravity>& gravities) //给带有Spawn状态实体的加上重力
{
	gravities.Create(e, 1);
}

extern "C" _declspec(dllexport) void Register(ESL::States& st, ESL::LogicGraphBuilder& graphBuilder) //注册插件逻辑
{
	st.Create<EGravity>();
	graphBuilder.Create(Logic_Gravity, "Gravity").Depends("Move");
	ESL::Dispatch(st, Init);
}





BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

