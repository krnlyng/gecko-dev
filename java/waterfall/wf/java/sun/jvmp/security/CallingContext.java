/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * 
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is The Waterfall Java Plugin Module
 * 
 * The Initial Developer of the Original Code is Sun Microsystems Inc
 * Portions created by Sun Microsystems Inc are Copyright (C) 2001
 * All Rights Reserved.
 *
 * $Id: CallingContext.java,v 1.1 2001/05/09 17:30:03 edburns%acm.org Exp $
 *
 * 
 * Contributor(s): 
 *
 *   Nikolay N. Igotti <inn@sparc.spb.su>
 */

package sun.jvmp.security;

import java.security.*;

public class CallingContext
{    
    private AccessControlContext acc;
    private SecurityCaps         caps;
    private ProtectionDomain     domain;
      
    public CallingContext(ProtectionDomain domain, byte[] raw_caps)
    {
	acc = AccessController.getContext();
	this.domain = domain;
	caps = new SecurityCaps(raw_caps);	
    }

    public CallingContext(SecurityCaps caps)
    {
	this.caps = caps;
    }           
}
