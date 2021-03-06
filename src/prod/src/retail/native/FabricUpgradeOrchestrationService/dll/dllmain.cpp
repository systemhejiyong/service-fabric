// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#include "stdafx.h"

#include "FabricUpgradeOrchestrationService_.h"

BOOL APIENTRY DllMain(
    HMODULE module,
    DWORD reason,
    LPVOID reserved)
{
    UNREFERENCED_PARAMETER(module);
    UNREFERENCED_PARAMETER(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


//
// WARNING: 
//
// The signature below MUST exactly match (including the parameter names)
// with the signature generated by MIDL in the FabricStore.h file. 
// Otherwise the linker does not apply the extern "C" specifier and exports 
// this function as C++ name mangled function instead of C style function.
// 
/* [entry] */ HRESULT CreateFabricUpgradeOrchestrationServiceAgent( 
    /* [in] */ __RPC__in REFIID riid,
    /* [out, retval] */ __RPC__deref_out_opt void ** fabricUpgradeOrchestrationServiceAgent)
{
    Common::DllConfig::GetConfig();

    if (Common::TraceTextFileSink::IsEnabled())
    {
        Common::TraceTextFileSink::SetOption(L"m");
    }

    auto factoryPtr = Management::UpgradeOrchestrationService::UpgradeOrchestrationServiceAgentFactory::Create();

    Api::ComUpgradeOrchestrationServiceAgentFactory comFactory(factoryPtr);

    return comFactory.CreateFabricUpgradeOrchestrationServiceAgent(riid, fabricUpgradeOrchestrationServiceAgent);
}
