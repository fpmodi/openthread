#!/usr/bin/env python
#
#  Copyright (c) 2018, The OpenThread Authors.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. Neither the name of the copyright holder nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.

from wpan import verify
import wpan
import time

#-----------------------------------------------------------------------------------------------------------------------
# Test description: discover scan

test_name = __file__[:-3] if __file__.endswith('.py') else __file__
print '-' * 120
print 'Starting \'{}\''.format(test_name)

#-----------------------------------------------------------------------------------------------------------------------
# Creating `wpan.Nodes` instances

NUM_NODES = 5

nodes = []
for i in range(NUM_NODES):
    nodes.append(wpan.Node())

scanner = wpan.Node()

#-----------------------------------------------------------------------------------------------------------------------
# Init all nodes

wpan.Node.init_all_nodes()

#-----------------------------------------------------------------------------------------------------------------------
# Build network topology

for node in nodes:
    node.form(node.interface_name)

#-----------------------------------------------------------------------------------------------------------------------
# Test implementation

# Perform active scan and check that all nodes are seen in the scan result.

scan_result = wpan.parse_scan_result(scanner.discover_scan())

for node in nodes:
    verify(node.is_in_scan_result(scan_result))

# Scan from an already associated node.

scan_result = wpan.parse_scan_result(nodes[0].discover_scan())

for node in nodes[1:]:
    verify(node.is_in_scan_result(scan_result))

# TODO: add tests for the joiner only and filtering

#-----------------------------------------------------------------------------------------------------------------------
# Test finished

print '\'{}\' passed.'.format(test_name)

