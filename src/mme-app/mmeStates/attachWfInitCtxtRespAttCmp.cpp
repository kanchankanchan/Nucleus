
/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * attachWfInitCtxtRespAttCmp.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/


#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"
#include "mmeSmDefs.h"
#include "utils/mmeStatesUtils.h"
#include "utils/mmeTimerTypes.h"

#include "mmeStates/attachWfInitCtxtRespAttCmp.h"	
#include "mmeStates/attachWfAttCmp.h"	
#include "mmeStates/attachWfInitCtxtResp.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
AttachWfInitCtxtRespAttCmp::AttachWfInitCtxtRespAttCmp():State(attach_wf_init_ctxt_resp_att_cmp, defaultStateGuardTimerDuration_c)
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
}

/******************************************************************************
* Destructor
******************************************************************************/
AttachWfInitCtxtRespAttCmp::~AttachWfInitCtxtRespAttCmp()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
AttachWfInitCtxtRespAttCmp* AttachWfInitCtxtRespAttCmp::Instance()
{
        static AttachWfInitCtxtRespAttCmp state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void AttachWfInitCtxtRespAttCmp::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_init_ctxt_resp);
                actionTable.setNextState(AttachWfAttCmp::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(INIT_CTXT_RESP_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_attach_cmp_from_ue);
                actionTable.setNextState(AttachWfInitCtxtResp::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ATT_CMP_FROM_UE, actionTable));
        }
}
