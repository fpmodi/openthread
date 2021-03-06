/*
 *  Copyright (c) 2017, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <openthread/config.h>
#include <openthread/platform/diag.h>

#if OPENTHREAD_ENABLE_DIAG

/**
 * Diagnostics mode variables.
 *
 */
static bool sDiagMode = false;

void otPlatDiagProcess(otInstance *aInstance, int argc, char *argv[], char *aOutput, size_t aOutputMaxLen)
{
    // Add more platform specific diagnostics features here.
    if (argc > 1)
    {
        snprintf(aOutput, aOutputMaxLen, "diag feature '%s' is not supported\r\n", argv[0]);
    }

    (void)argc;
    (void)aInstance;
}

void otPlatDiagModeSet(bool aMode)
{
    sDiagMode = aMode;
}

bool otPlatDiagModeGet()
{
    return sDiagMode;
}

void otPlatDiagChannelSet(uint8_t aChannel)
{
    (void)aChannel;
}

void otPlatDiagTxPowerSet(int8_t aTxPower)
{
    (void)aTxPower;
}

void otPlatDiagRadioReceived(otInstance *aInstance, otRadioFrame *aFrame, otError aError)
{
    (void)aInstance;
    (void)aFrame;
    (void)aError;
}

void otPlatDiagAlarmCallback(otInstance *aInstance)
{
    (void)aInstance;
}

#endif // OPENTHREAD_ENABLE_DIAG
