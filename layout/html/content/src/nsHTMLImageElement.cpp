/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is Netscape Communications
 * Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 */
#include "nsIDOMHTMLImageElement.h"
#include "nsIDOMImage.h"
#include "nsIScriptObjectOwner.h"
#include "nsIDOMEventReceiver.h"
#include "nsIHTMLContent.h"
#include "nsGenericHTMLElement.h"
#include "nsHTMLAtoms.h"
#include "nsHTMLIIDs.h"
#include "nsIStyleContext.h"
#include "nsIMutableStyleContext.h"
#include "nsStyleConsts.h"
#include "nsIPresContext.h"
#include "nsIPresShell.h"
#include "nsIHTMLAttributes.h"
#include "nsIJSScriptObject.h"
#include "nsIJSNativeInitializer.h"
#include "nsSize.h"
#include "nsIDocument.h"
#include "nsIDOMWindow.h"
#include "nsIDOMDocument.h"
#include "nsIScriptContext.h"
#include "nsIScriptGlobalObject.h"
#include "nsIURL.h"
#include "nsIIOService.h"
#include "nsIURL.h"
#include "nsIServiceManager.h"
#include "nsNetUtil.h"
#include "nsLayoutUtils.h"
#include "nsIWebShell.h"
#include "nsIFrame.h"
#include "nsImageFrame.h"
#include "nsLayoutAtoms.h"
#include "nsNodeInfoManager.h"

static NS_DEFINE_CID(kIOServiceCID, NS_IOSERVICE_CID);

// XXX nav attrs: suppress

static NS_DEFINE_IID(kIDOMHTMLImageElementIID, NS_IDOMHTMLIMAGEELEMENT_IID);
static NS_DEFINE_IID(kIDOMImageIID, NS_IDOMIMAGE_IID);
static NS_DEFINE_IID(kIJSNativeInitializerIID, NS_IJSNATIVEINITIALIZER_IID);
static NS_DEFINE_IID(kIDOMWindowIID, NS_IDOMWINDOW_IID);
static NS_DEFINE_IID(kIDocumentIID, NS_IDOCUMENT_IID);

class nsHTMLImageElement : public nsIDOMHTMLImageElement,
                           public nsIDOMImage,
                           public nsIJSScriptObject,
                           public nsIHTMLContent,
                           public nsIJSNativeInitializer
{
public:
  nsHTMLImageElement(nsINodeInfo *aNodeInfo);
  virtual ~nsHTMLImageElement();

  // nsISupports
  NS_DECL_ISUPPORTS

  // nsIDOMNode
  NS_IMPL_IDOMNODE_USING_GENERIC(mInner)

  // nsIDOMElement
  NS_IMPL_IDOMELEMENT_USING_GENERIC(mInner)

  // nsIDOMHTMLElement
  NS_IMPL_IDOMHTMLELEMENT_USING_GENERIC(mInner)

  // nsIDOMHTMLImageElement
  NS_IMETHOD GetLowSrc(nsString& aLowSrc);
  NS_IMETHOD SetLowSrc(const nsString& aLowSrc);
  NS_IMETHOD GetName(nsString& aName);
  NS_IMETHOD SetName(const nsString& aName);
  NS_IMETHOD GetAlign(nsString& aAlign);
  NS_IMETHOD SetAlign(const nsString& aAlign);
  NS_IMETHOD GetAlt(nsString& aAlt);
  NS_IMETHOD SetAlt(const nsString& aAlt);
  NS_IMETHOD GetBorder(nsString& aBorder);
  NS_IMETHOD SetBorder(const nsString& aBorder);
  NS_IMETHOD GetHeight(nsString& aHeight);
  NS_IMETHOD SetHeight(const nsString& aHeight);
  NS_IMETHOD GetHspace(nsString& aHspace);
  NS_IMETHOD SetHspace(const nsString& aHspace);
  NS_IMETHOD GetIsMap(PRBool* aIsMap);
  NS_IMETHOD SetIsMap(PRBool aIsMap);
  NS_IMETHOD GetLongDesc(nsString& aLongDesc);
  NS_IMETHOD SetLongDesc(const nsString& aLongDesc);
  NS_IMETHOD GetSrc(nsString& aSrc);
  NS_IMETHOD SetSrc(const nsString& aSrc);
  NS_IMETHOD GetUseMap(nsString& aUseMap);
  NS_IMETHOD SetUseMap(const nsString& aUseMap);
  NS_IMETHOD GetVspace(nsString& aVspace);
  NS_IMETHOD SetVspace(const nsString& aVspace);
  NS_IMETHOD GetWidth(nsString& aWidth);
  NS_IMETHOD SetWidth(const nsString& aWidth);

  // nsIDOMImage
  // XXX Casing is different for backward compatibility
  NS_IMETHOD    GetLowsrc(nsString& aLowsrc);
  NS_IMETHOD    SetLowsrc(const nsString& aLowsrc);
  NS_IMETHOD    GetComplete(PRBool* aComplete);
  NS_IMETHOD    GetBorder(PRInt32* aBorder);
  NS_IMETHOD    SetBorder(PRInt32 aBorder);
  NS_IMETHOD    GetHeight(PRInt32* aHeight);
  NS_IMETHOD    SetHeight(PRInt32 aHeight);
  NS_IMETHOD    GetHspace(PRInt32* aHspace);
  NS_IMETHOD    SetHspace(PRInt32 aHspace);
  NS_IMETHOD    GetVspace(PRInt32* aVspace);
  NS_IMETHOD    SetVspace(PRInt32 aVspace);
  NS_IMETHOD    GetWidth(PRInt32* aWidth);
  NS_IMETHOD    SetWidth(PRInt32 aWidth);


  // nsIContent
  NS_IMPL_ICONTENT_NO_SETDOCUMENT_USING_GENERIC(mInner)

  // nsIHTMLContent
  NS_IMPL_IHTMLCONTENT_USING_GENERIC(mInner)

  // nsIJSScriptObject
  NS_IMPL_ISCRIPTOBJECTOWNER_USING_GENERIC(mInner)
  virtual PRBool    AddProperty(JSContext *aContext, JSObject *aObj, 
                        jsval aID, jsval *aVp);
  virtual PRBool    DeleteProperty(JSContext *aContext, JSObject *aObj, 
                        jsval aID, jsval *aVp);
  virtual PRBool    GetProperty(JSContext *aContext, JSObject *aObj, 
                        jsval aID, jsval *aVp);
  virtual PRBool    SetProperty(JSContext *aContext, JSObject *aObj, 
                        jsval aID, jsval *aVp);
  virtual PRBool    EnumerateProperty(JSContext *aContext, JSObject *aObj);
  virtual PRBool    Resolve(JSContext *aContext, JSObject *aObj, jsval aID);
  virtual PRBool    Convert(JSContext *aContext, JSObject *aObj, jsval aID);
  virtual void      Finalize(JSContext *aContext, JSObject *aObj);

  // nsIJSNativeInitializer
  NS_IMETHOD Initialize(JSContext* aContext, JSObject *aObj, 
                        PRUint32 argc, jsval *argv);
  nsresult SetSrcInner(nsIURI* aBaseURL, const nsString& aSrc);
  nsresult GetCallerSourceURL(JSContext* cx, nsIURI** sourceURL);

  nsresult GetImageFrame(nsImageFrame** aImageFrame);

protected:
  nsGenericHTMLLeafElement mInner;
  nsIDocument* mOwnerDocument;  // Only used if this is a script constructed image
};

nsresult
NS_NewHTMLImageElement(nsIHTMLContent** aInstancePtrResult,
                       nsINodeInfo *aNodeInfo)
{
  NS_ENSURE_ARG_POINTER(aInstancePtrResult);

  /*
   * nsHTMLImageElement's will be created without a nsINodeInfo passed in
   * if someone says "var img = new Image();" in JavaScript, in a case like
   * that we request the nsINodeInfo from the anonymous nodeinfo list.
   */
  nsCOMPtr<nsINodeInfo> nodeInfo(aNodeInfo);
  if (!nodeInfo) {
    nsCOMPtr<nsINodeInfoManager> nodeInfoManager;
    nsresult rv;
    rv = nsNodeInfoManager::GetAnonymousManager(*getter_AddRefs(nodeInfoManager));
    NS_ENSURE_SUCCESS(rv, rv);

    rv = nodeInfoManager->GetNodeInfo(nsHTMLAtoms::img, nsnull,
                                      kNameSpaceID_None,
                                      *getter_AddRefs(nodeInfo));
    NS_ENSURE_SUCCESS(rv, rv);
  }

  nsIHTMLContent* it = new nsHTMLImageElement(nodeInfo);
  if (nsnull == it) {
    return NS_ERROR_OUT_OF_MEMORY;
  }
  return it->QueryInterface(kIHTMLContentIID, (void**) aInstancePtrResult);
}


nsHTMLImageElement::nsHTMLImageElement(nsINodeInfo *aNodeInfo)
{
  NS_INIT_REFCNT();
  mInner.Init(this, aNodeInfo);
  mOwnerDocument = nsnull;
}

nsHTMLImageElement::~nsHTMLImageElement()
{
  NS_IF_RELEASE(mOwnerDocument);
}

NS_IMPL_ADDREF(nsHTMLImageElement)

NS_IMPL_RELEASE(nsHTMLImageElement)

nsresult
nsHTMLImageElement::QueryInterface(REFNSIID aIID, void** aInstancePtr)
{
  // Note that this has to stay above the generic element
  // QI macro, since it overrides the nsIJSScriptObject implementation
  // from the generic element.
  if (aIID.Equals(kIJSScriptObjectIID)) {
    nsIJSScriptObject* tmp = this;
    *aInstancePtr = (void*) tmp;
    AddRef();
    return NS_OK;
  }                                                             
  NS_IMPL_HTML_CONTENT_QUERY_INTERFACE(aIID, aInstancePtr, this)
  if (aIID.Equals(kIDOMHTMLImageElementIID)) {
    nsIDOMHTMLImageElement* tmp = this;
    *aInstancePtr = (void*) tmp;
    NS_ADDREF_THIS();
    return NS_OK;
  }
  if (aIID.Equals(kIDOMImageIID)) {
    nsIDOMImage* tmp = this;
    *aInstancePtr = (void*) tmp;
    NS_ADDREF_THIS();
    return NS_OK;
  }
  if (aIID.Equals(kIJSNativeInitializerIID)) {
    nsIJSNativeInitializer* tmp = this;
    *aInstancePtr = (void*) tmp;
    NS_ADDREF_THIS();
    return NS_OK;
  }
  return NS_NOINTERFACE;
}

nsresult
nsHTMLImageElement::CloneNode(PRBool aDeep, nsIDOMNode** aReturn)
{
  nsHTMLImageElement* it = new nsHTMLImageElement(mInner.mNodeInfo);
  if (nsnull == it) {
    return NS_ERROR_OUT_OF_MEMORY;
  }
  nsCOMPtr<nsIDOMNode> kungFuDeathGrip(it);
  mInner.CopyInnerTo(this, &it->mInner, aDeep);
  return it->QueryInterface(kIDOMNodeIID, (void**) aReturn);
}

NS_IMPL_STRING_ATTR(nsHTMLImageElement, LowSrc, lowsrc)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Name, name)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Align, align)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Alt, alt)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Border, border)
NS_IMPL_INT_ATTR(nsHTMLImageElement, Border, border)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Hspace, hspace)
NS_IMPL_INT_ATTR(nsHTMLImageElement, Hspace, hspace)
NS_IMPL_BOOL_ATTR(nsHTMLImageElement, IsMap, ismap)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, LongDesc, longdesc)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Lowsrc, lowsrc)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, UseMap, usemap)
NS_IMPL_STRING_ATTR(nsHTMLImageElement, Vspace, vspace)
NS_IMPL_INT_ATTR(nsHTMLImageElement, Vspace, vspace)

nsresult
nsHTMLImageElement::GetImageFrame(nsImageFrame** aImageFrame)
{
  nsresult result;
  nsCOMPtr<nsIPresContext> context;
  nsCOMPtr<nsIPresShell> shell;
  
  if (mInner.mDocument) {
    // Make sure the presentation is up-to-date
    result = mInner.mDocument->FlushPendingNotifications();
    if (NS_FAILED(result)) {
      return result;
    }
  }
  
  result = nsGenericHTMLElement::GetPresContext(this, 
                                                getter_AddRefs(context));
  if (NS_FAILED(result)) {
    return result;
  }
  
  result = context->GetShell(getter_AddRefs(shell));
  if (NS_FAILED(result)) {
    return result;
  }
  
  nsIFrame* frame;
  result = shell->GetPrimaryFrameFor(this, &frame);
  if (NS_FAILED(result)) {
    return result;
  }
  
  if (frame) {
    nsCOMPtr<nsIAtom> type;
    
    frame->GetFrameType(getter_AddRefs(type));
    
    if (type.get() == nsLayoutAtoms::imageFrame) {
      // XXX We could have created an interface for this, but Troy
      // preferred the ugliness of a static cast to the weight of
      // a new interface.
      nsImageFrame* imageFrame = NS_STATIC_CAST(nsImageFrame*, frame);
      *aImageFrame = imageFrame;
      
      return NS_OK;
    }
  }

  return NS_ERROR_FAILURE;
}

NS_IMETHODIMP    
nsHTMLImageElement::GetComplete(PRBool* aComplete)
{
  NS_ENSURE_ARG_POINTER(aComplete);
  *aComplete = PR_FALSE;

  nsresult result;
  nsImageFrame* imageFrame;

  result = GetImageFrame(&imageFrame);
  if (NS_SUCCEEDED(result)) {
    result = imageFrame->IsImageComplete(aComplete);
  }

  return NS_OK;
}

NS_IMETHODIMP
nsHTMLImageElement::GetHeight(nsString& aValue)
{
  nsresult rv = mInner.GetAttribute(kNameSpaceID_None, nsHTMLAtoms::height,
                                    aValue);

  if (rv == NS_CONTENT_ATTR_NOT_THERE) {
    PRInt32 height = 0;

    aValue.Truncate(); 

    // A zero height most likely means that the image is not loaded yet.
    if (NS_SUCCEEDED(GetHeight(&height)) && height) {
      aValue.AppendInt(height);
      aValue.AppendWithConversion("px");
    }
  }

  return NS_OK;
}

NS_IMETHODIMP
nsHTMLImageElement::SetHeight(const nsString& aValue)
{
  return mInner.SetAttribute(kNameSpaceID_None, nsHTMLAtoms::height, aValue,
                             PR_TRUE);
}

NS_IMETHODIMP
nsHTMLImageElement::GetHeight(PRInt32* aHeight)
{
  NS_ENSURE_ARG_POINTER(aHeight);
  *aHeight = 0;

  nsImageFrame* imageFrame;

  nsresult rv = GetImageFrame(&imageFrame);

  if (NS_SUCCEEDED(rv) && imageFrame) {
    nsSize size;
    imageFrame->GetSize(size);

    nsCOMPtr<nsIPresContext> context;
    rv = nsGenericHTMLElement::GetPresContext(this, getter_AddRefs(context));

    if (NS_SUCCEEDED(rv) && context) {
      float t2p;
      context->GetTwipsToPixels(&t2p);

      *aHeight = NSTwipsToIntPixels(size.height, t2p);
    }
  } else {
    nsHTMLValue value;
    rv = mInner.GetHTMLAttribute(nsHTMLAtoms::height, value);

    if (rv == NS_CONTENT_ATTR_HAS_VALUE) {
      *aHeight = value.GetPixelValue();
    }
  }

  return NS_OK;
}

NS_IMETHODIMP
nsHTMLImageElement::SetHeight(PRInt32 aHeight)
{
  nsAutoString val;

  val.AppendInt(aHeight);

  return mInner.SetAttribute(kNameSpaceID_None, nsHTMLAtoms::height,
                             val, PR_TRUE);
}

NS_IMETHODIMP
nsHTMLImageElement::GetWidth(nsString& aValue)
{
  nsresult rv = mInner.GetAttribute(kNameSpaceID_None, nsHTMLAtoms::width,
                                    aValue);

  if (rv == NS_CONTENT_ATTR_NOT_THERE) {
    PRInt32 width = 0;

    aValue.Truncate(); 

    // A zero width most likely means that the image is not loaded yet.
    if (NS_SUCCEEDED(GetWidth(&width)) && width) {
      aValue.AppendInt(width);
      aValue.AppendWithConversion("px");
    }
  }

  return NS_OK;
}

NS_IMETHODIMP
nsHTMLImageElement::SetWidth(const nsString& aValue)
{
  return mInner.SetAttribute(kNameSpaceID_None, nsHTMLAtoms::width, aValue,
                             PR_TRUE);
}

NS_IMETHODIMP
nsHTMLImageElement::GetWidth(PRInt32* aWidth)
{
  NS_ENSURE_ARG_POINTER(aWidth);
  *aWidth = 0;

  nsImageFrame* imageFrame;

  nsresult rv = GetImageFrame(&imageFrame);

  if (NS_SUCCEEDED(rv) && imageFrame) {
    nsSize size;
    imageFrame->GetSize(size);

    nsCOMPtr<nsIPresContext> context;
    rv = nsGenericHTMLElement::GetPresContext(this, getter_AddRefs(context));

    if (NS_SUCCEEDED(rv) && context) {
      float t2p;
      context->GetTwipsToPixels(&t2p);

      *aWidth = NSTwipsToIntPixels(size.width, t2p);
    }
  } else {
    nsHTMLValue value;
    rv = mInner.GetHTMLAttribute(nsHTMLAtoms::width, value);

    if (rv == NS_CONTENT_ATTR_HAS_VALUE) {
      *aWidth = value.GetPixelValue();
    }
  }

  return NS_OK;
}

NS_IMETHODIMP
nsHTMLImageElement::SetWidth(PRInt32 aWidth)
{
  nsAutoString val;

  val.AppendInt(aWidth);

  return mInner.SetAttribute(kNameSpaceID_None, nsHTMLAtoms::width,
                             val, PR_TRUE);
}

NS_IMETHODIMP
nsHTMLImageElement::StringToAttribute(nsIAtom* aAttribute,
                                      const nsString& aValue,
                                      nsHTMLValue& aResult)
{
  if (aAttribute == nsHTMLAtoms::align) {
    if (nsGenericHTMLElement::ParseAlignValue(aValue, aResult)) {
      return NS_CONTENT_ATTR_HAS_VALUE;
    }
  }
  else if (aAttribute == nsHTMLAtoms::ismap) {
    aResult.SetEmptyValue();
    return NS_CONTENT_ATTR_HAS_VALUE;
  }
  else if (nsGenericHTMLElement::ParseImageAttribute(aAttribute,
                                                     aValue, aResult)) {
    return NS_CONTENT_ATTR_HAS_VALUE;
  }
  return NS_CONTENT_ATTR_NOT_THERE;
}

NS_IMETHODIMP
nsHTMLImageElement::AttributeToString(nsIAtom* aAttribute,
                                      const nsHTMLValue& aValue,
                                      nsString& aResult) const
{
  if (aAttribute == nsHTMLAtoms::align) {
    if (eHTMLUnit_Enumerated == aValue.GetUnit()) {
      nsGenericHTMLElement::AlignValueToString(aValue, aResult);
      return NS_CONTENT_ATTR_HAS_VALUE;
    }
  }
  else if (nsGenericHTMLElement::ImageAttributeToString(aAttribute,
                                                        aValue, aResult)) {
    return NS_CONTENT_ATTR_HAS_VALUE;
  }
  return mInner.AttributeToString(aAttribute, aValue, aResult);
}

static void
MapAttributesInto(const nsIHTMLMappedAttributes* aAttributes,
                  nsIMutableStyleContext* aContext,
                  nsIPresContext* aPresContext)
{
  if (nsnull != aAttributes) {
    nsHTMLValue value;
    aAttributes->GetAttribute(nsHTMLAtoms::align, value);
    if (value.GetUnit() == eHTMLUnit_Enumerated) {
      PRUint8 align = value.GetIntValue();
      nsStyleDisplay* display = (nsStyleDisplay*)
        aContext->GetMutableStyleData(eStyleStruct_Display);
      nsStyleText* text = (nsStyleText*)
        aContext->GetMutableStyleData(eStyleStruct_Text);
      switch (align) {
      case NS_STYLE_TEXT_ALIGN_LEFT:
        display->mFloats = NS_STYLE_FLOAT_LEFT;
        break;
      case NS_STYLE_TEXT_ALIGN_RIGHT:
        display->mFloats = NS_STYLE_FLOAT_RIGHT;
        break;
      default:
        text->mVerticalAlign.SetIntValue(align, eStyleUnit_Enumerated);
        break;
      }
    }
  }
  nsGenericHTMLElement::MapImageAttributesInto(aAttributes, aContext, aPresContext);
  nsGenericHTMLElement::MapImageBorderAttributeInto(aAttributes, aContext, aPresContext, nsnull);
  nsGenericHTMLElement::MapCommonAttributesInto(aAttributes, aContext, aPresContext);
}

NS_IMETHODIMP
nsHTMLImageElement::GetMappedAttributeImpact(const nsIAtom* aAttribute,
                                             PRInt32& aHint) const
{
  if ((aAttribute == nsHTMLAtoms::usemap) ||
      (aAttribute == nsHTMLAtoms::ismap)) {
    aHint = NS_STYLE_HINT_FRAMECHANGE;
  }
  else if (aAttribute == nsHTMLAtoms::align) {
    aHint = NS_STYLE_HINT_REFLOW;
  }
  else if (! nsGenericHTMLElement::GetCommonMappedAttributesImpact(aAttribute, aHint)) {
    if (! nsGenericHTMLElement::GetImageMappedAttributesImpact(aAttribute, aHint)) {
      if (! nsGenericHTMLElement::GetImageBorderAttributeImpact(aAttribute, aHint)) {
        aHint = NS_STYLE_HINT_CONTENT;
      }
    }
  }

  return NS_OK;
}


NS_IMETHODIMP
nsHTMLImageElement::GetAttributeMappingFunctions(nsMapAttributesFunc& aFontMapFunc,
                                                 nsMapAttributesFunc& aMapFunc) const
{
  aFontMapFunc = nsnull;
  aMapFunc = &MapAttributesInto;
  return NS_OK;
}


NS_IMETHODIMP
nsHTMLImageElement::HandleDOMEvent(nsIPresContext* aPresContext,
                                   nsEvent* aEvent,
                                   nsIDOMEvent** aDOMEvent,
                                   PRUint32 aFlags,
                                   nsEventStatus* aEventStatus)
{
  // If we are a map and get a mouse click, don't let it be handled by the
  // Generic Element as this could cause a click event to fire twice, once by
  // the image frame for the map and once by the Anchor element.  (bug 39723)
  if (NS_MOUSE_LEFT_CLICK == aEvent->message) {
    PRBool isMap = PR_FALSE;
    GetIsMap(&isMap);
    if (isMap) {
      *aEventStatus = nsEventStatus_eConsumeNoDefault;
    }
  }
  return mInner.HandleDOMEvent(aPresContext, aEvent, aDOMEvent,
                               aFlags, aEventStatus);
}

PRBool    
nsHTMLImageElement::AddProperty(JSContext *aContext, JSObject *aObj, jsval aID, jsval *aVp)
{
  return mInner.AddProperty(aContext, aObj, aID, aVp);
}

PRBool    
nsHTMLImageElement::DeleteProperty(JSContext *aContext, JSObject *aObj, jsval aID, jsval *aVp)
{
  return mInner.DeleteProperty(aContext, aObj, aID, aVp);
}

PRBool    
nsHTMLImageElement::GetProperty(JSContext *aContext, JSObject *aObj, jsval aID, jsval *aVp)
{
  // XXX Security manager needs to be called
  if (JSVAL_IS_STRING(aID)) {
    char* cString = JS_GetStringBytes(JS_ValueToString(aContext, aID));
    if (PL_strcmp("src", cString) == 0) {
      nsAutoString src;
      if (NS_SUCCEEDED(GetSrc(src))) {
        const PRUnichar* bytes = src.GetUnicode();
        JSString* str = JS_NewUCStringCopyZ(aContext, (const jschar*)bytes);
        if (str) {
          *aVp = STRING_TO_JSVAL(str);
          return PR_TRUE;
        }
        else {
          return PR_FALSE;
        }
      }
      else {
        return PR_FALSE;
      }
    }
  }

  return mInner.GetProperty(aContext, aObj, aID, aVp);
}

nsresult
nsHTMLImageElement::GetCallerSourceURL(JSContext* cx,
                                       nsIURI** sourceURL)
{
  // XXX Code duplicated from nsHTMLDocument
  // XXX Question, why does this return NS_OK on failure?
  nsresult result = NS_OK;

  // We need to use the dynamically scoped global and assume that the 
  // current JSContext is a DOM context with a nsIScriptGlobalObject so
  // that we can get the url of the caller.
  // XXX This will fail on non-DOM contexts :(

  nsCOMPtr<nsIScriptGlobalObject> global;
  nsLayoutUtils::GetDynamicScriptGlobal(cx, getter_AddRefs(global));
  if (global) {
    nsCOMPtr<nsIDOMWindow> window = do_QueryInterface(global);

    if (window) {
      nsCOMPtr<nsIDOMDocument> domDoc;

      result = window->GetDocument(getter_AddRefs(domDoc));
      if (NS_SUCCEEDED(result)) {
        nsCOMPtr<nsIDocument> doc = do_QueryInterface(domDoc);

        if (doc) {
          result = doc->GetBaseURL(*sourceURL);
          if (!*sourceURL) {
            *sourceURL = doc->GetDocumentURL();
          }
        }
      }
    }
  }

  return result;
}

PRBool    
nsHTMLImageElement::SetProperty(JSContext *aContext, JSObject *aObj, jsval aID, jsval *aVp)
{
  nsresult result = NS_OK;

  // XXX Security manager needs to be called
  if (JSVAL_IS_STRING(aID)) {
    char* cString = JS_GetStringBytes(JS_ValueToString(aContext, aID));
    
    if (PL_strcmp("src", cString) == 0) {
      nsCOMPtr<nsIURI> base;
      nsAutoString src, url;
      
      // Get the parameter passed in
      JSString *jsstring;
      if ((jsstring = JS_ValueToString(aContext, *aVp)) != nsnull) {
        src.Assign(NS_REINTERPRET_CAST(const PRUnichar*, JS_GetStringChars(jsstring)));
      }
      else {
        src.Truncate();
      }
      
      // Get the source of the caller
      result = GetCallerSourceURL(aContext, getter_AddRefs(base));
      
      if (NS_SUCCEEDED(result)) {
        result = NS_MakeAbsoluteURI(url, src, base);
        if (NS_SUCCEEDED(result)) {
          result = SetSrcInner(base, url);
        }
      }
    }
    else {
      result = mInner.SetProperty(aContext, aObj, aID, aVp);
    }
  }
  else {
    result = mInner.SetProperty(aContext, aObj, aID, aVp);
  }
  
  if (NS_FAILED(result)) {
    return PR_FALSE;
  }

  return PR_TRUE;
}

PRBool    
nsHTMLImageElement::EnumerateProperty(JSContext *aContext, JSObject *aObj)
{
  return mInner.EnumerateProperty(aContext, aObj);
}

PRBool    
nsHTMLImageElement::Resolve(JSContext *aContext, JSObject *aObj, jsval aID)
{
  return mInner.Resolve(aContext, aObj, aID);
}

PRBool    
nsHTMLImageElement::Convert(JSContext *aContext, JSObject *aObj, jsval aID)
{
  return mInner.Convert(aContext, aObj, aID);
}

void      
nsHTMLImageElement::Finalize(JSContext *aContext, JSObject *aObj)
{
  mInner.Finalize(aContext, aObj);
}


NS_IMETHODIMP    
nsHTMLImageElement::Initialize(JSContext* aContext,
                               JSObject *aObj,
                               PRUint32 argc, 
                               jsval *argv)
{
  nsresult result = NS_OK;

  // XXX This element is created unattached to any document.  Later
  // on, it might be used to preload the image cache.  For that, we
  // need a document (actually a pres context).  The only way to get
  // one is to associate the image with one at creation time.
  // This is safer than it used to be since we get the global object
  // from the static scope chain rather than through the JSCOntext.

  nsCOMPtr<nsIScriptGlobalObject> globalObject;
  nsLayoutUtils::GetStaticScriptGlobal(aContext, aObj,
                                       getter_AddRefs(globalObject));;
  if (globalObject) {
    nsIDOMWindow* domWindow;
    result = globalObject->QueryInterface(kIDOMWindowIID, (void**)&domWindow);
    if (NS_SUCCEEDED(result)) {
      nsIDOMDocument* domDocument;
      result = domWindow->GetDocument(&domDocument);
      if (NS_SUCCEEDED(result)) {
        // Maintain the reference
        result = domDocument->QueryInterface(kIDocumentIID, 
                                             (void**)&mOwnerDocument);
        NS_RELEASE(domDocument);
      }
      NS_RELEASE(domWindow);
    }
  }

  if (NS_SUCCEEDED(result) && (argc > 0)) {
    // The first (optional) argument is the width of the image
    int32 width;
    JSBool ret = JS_ValueToInt32(aContext, argv[0], &width);
    if (ret) {
      nsHTMLValue widthVal((PRInt32)width, eHTMLUnit_Integer);

      result = mInner.SetHTMLAttribute(nsHTMLAtoms::width,
                                       widthVal, PR_FALSE);
      
      if (NS_SUCCEEDED(result) && (argc > 1)) {
        // The second (optional) argument is the height of the image
        int32 height;
        ret = JS_ValueToInt32(aContext, argv[1], &height);
        if (ret) {
          nsHTMLValue heightVal((PRInt32)height, eHTMLUnit_Integer);
          
          result = mInner.SetHTMLAttribute(nsHTMLAtoms::height,
                                           heightVal, PR_FALSE);
        }
        else {
          result = NS_ERROR_INVALID_ARG;
        }
      }
    }
    else {
      result = NS_ERROR_INVALID_ARG;
    }
  }

  return result;
}

NS_IMETHODIMP 
nsHTMLImageElement::SetDocument(nsIDocument* aDocument, 
                                PRBool aDeep, PRBool aCompileEventHandlers)
{
  // If we've been added to the document, we can get rid of 
  // our owner document reference so as to avoid a circular
  // reference.
  NS_IF_RELEASE(mOwnerDocument);
  return mInner.SetDocument(aDocument, aDeep, aCompileEventHandlers);
}

NS_IMETHODIMP
nsHTMLImageElement::GetSrc(nsString& aSrc)
{
  // Resolve url to an absolute url
  nsresult rv = NS_OK;
  nsAutoString relURLSpec;
  nsIURI* baseURL = nsnull;

  // Get base URL.
  GetBaseURL(baseURL);

  // Get href= attribute (relative URL).
  mInner.GetAttribute(kNameSpaceID_HTML, nsHTMLAtoms::src, relURLSpec);

  if (nsnull != baseURL && relURLSpec.Length() > 0) {
    // Get absolute URL.
    rv = NS_MakeAbsoluteURI(aSrc, relURLSpec, baseURL);
  }
  else {
    // Absolute URL is same as relative URL.
    aSrc = relURLSpec;
  }
  NS_IF_RELEASE(baseURL);
  return rv;
}

nsresult
nsHTMLImageElement::SetSrcInner(nsIURI* aBaseURL, const nsString& aSrc)
{
  nsresult result = NS_OK;

  if (nsnull != mOwnerDocument) {
    
    PRInt32 i, count = mOwnerDocument->GetNumberOfShells();
    nsIPresShell* shell;

    for (i = 0; i < count; i++) {
      shell = mOwnerDocument->GetShellAt(i);
      if (nsnull != shell) {
        nsIPresContext* context;
        
        result = shell->GetPresContext(&context);
        if (NS_SUCCEEDED(result)) {
          nsSize size;
          nsHTMLValue val;
          float p2t;
          
          context->GetScaledPixelsToTwips(&p2t);
          result = mInner.GetHTMLAttribute(nsHTMLAtoms::width, val);
          if (NS_CONTENT_ATTR_HAS_VALUE == result) {
            size.width = NSIntPixelsToTwips(val.GetIntValue(), p2t);
          }
          else {
            size.width = 0;
          }
          result = mInner.GetHTMLAttribute(nsHTMLAtoms::height, val);
          if (NS_CONTENT_ATTR_HAS_VALUE == result) {
            size.height = NSIntPixelsToTwips(val.GetIntValue(), p2t);
          }
          else {
            size.height = 0;
          }

          nsAutoString url;
          if (nsnull != aBaseURL) {
            result = NS_MakeAbsoluteURI(url, aSrc, aBaseURL);
            if (NS_FAILED(result)) {
              url.Assign(aSrc);
            }
          }
          else {
            url.Assign(aSrc);
          }

          nsSize* specifiedSize = nsnull;
          if ((size.width > 0) || (size.height > 0)) {
            specifiedSize = &size;
          }

          // Start the image loading. We don't care about notification
          // or holding on to the image loader.
          result = context->StartLoadImage(url, nsnull, specifiedSize,
                                           nsnull, nsnull, nsnull,
                                           nsnull);

          NS_RELEASE(context);
        }
        
        NS_RELEASE(shell);
      }
    }

    // Only do this the first time since it's only there for
    // backwards compatability
    NS_RELEASE(mOwnerDocument);
  }

  if (NS_SUCCEEDED(result)) {
    result = mInner.SetAttribute(kNameSpaceID_HTML, nsHTMLAtoms::src, aSrc, PR_TRUE);
  }

  return result;
}

NS_IMETHODIMP 
nsHTMLImageElement::SetSrc(const nsString& aSrc)
{
  nsIURI* baseURL = nsnull;
  nsresult result = NS_OK;

  if (nsnull != mOwnerDocument) {
    result = mOwnerDocument->GetBaseURL(baseURL);
  }
  
  if (NS_SUCCEEDED(result)) {
    result = SetSrcInner(baseURL, aSrc);
    NS_IF_RELEASE(baseURL);
  }

  return result;
}

NS_IMETHODIMP
nsHTMLImageElement::SizeOf(nsISizeOfHandler* aSizer, PRUint32* aResult) const
{
  return mInner.SizeOf(aSizer, aResult, sizeof(*this));
}

