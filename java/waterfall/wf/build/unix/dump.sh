# 
# The contents of this file are subject to the Mozilla Public
# License Version 1.1 (the "License"); you may not use this file
# except in compliance with the License. You may obtain a copy of
# the License at http://www.mozilla.org/MPL/
# 
# Software distributed under the License is distributed on an "AS
# IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
# implied. See the License for the specific language governing
# rights and limitations under the License.
# 
# The Original Code is The Waterfall Java Plugin Module
# 
# The Initial Developer of the Original Code is Sun Microsystems Inc
# Portions created by Sun Microsystems Inc are Copyright (C) 2001
# All Rights Reserved.
#
# $Id: dump.sh,v 1.1 2001/05/09 17:29:53 edburns%acm.org Exp $
#
# 
# Contributor(s): 
#
#   Nikolay N. Igotti <inn@sparc.spb.su>

tar czvf /tmp/jp.tgz /ws/M2308/mozilla/modules/jvmp/java/  /ws/M2308/mozilla/modules/jvmp/public/ /ws/M2308/mozilla/modules/jvmp/src/ /ws/M2308/mozilla/modules/jvmp/build/java/ /ws/M2308/mozilla/modules/jvmp/build/unix/GNUmakefile
