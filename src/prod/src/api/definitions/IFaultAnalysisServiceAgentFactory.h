// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once 

namespace Api
{
    class IFaultAnalysisServiceAgentFactory
    {
    public:
        virtual ~IFaultAnalysisServiceAgentFactory() {};

        virtual Common::ErrorCode CreateFaultAnalysisServiceAgent(
            __out IFaultAnalysisServiceAgentPtr &) = 0;
    };
}
