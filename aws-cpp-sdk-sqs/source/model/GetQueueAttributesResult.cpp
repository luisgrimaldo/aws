﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/sqs/model/GetQueueAttributesResult.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <utility>

using namespace Aws::SQS::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils::Logging;
using namespace Aws::Utils;
using namespace Aws;

GetQueueAttributesResult::GetQueueAttributesResult()
{
}

GetQueueAttributesResult::GetQueueAttributesResult(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

GetQueueAttributesResult& GetQueueAttributesResult::operator =(const Aws::AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (!rootNode.IsNull() && (rootNode.GetName() != "GetQueueAttributesResult"))
  {
    resultNode = rootNode.FirstChild("GetQueueAttributesResult");
  }

  if(!resultNode.IsNull())
  {
    XmlNode attributesNode = resultNode.FirstChild("Attribute");
    if(!attributesNode.IsNull())
    {
      XmlNode attributeEntry = attributesNode;
      while(!attributeEntry.IsNull())
      {
        XmlNode keyNode = attributeEntry.FirstChild("Name");
        XmlNode valueNode = attributeEntry.FirstChild("Value");
        m_attributes[QueueAttributeNameMapper::GetQueueAttributeNameForName(StringUtils::Trim(keyNode.GetText().c_str()))] =
            valueNode.GetText();
        attributeEntry = attributeEntry.NextNode("Attribute");
      }

    }
  }

  if (!rootNode.IsNull()) {
    XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
    m_responseMetadata = responseMetadataNode;
    AWS_LOGSTREAM_DEBUG("Aws::SQS::Model::GetQueueAttributesResult", "x-amzn-request-id: " << m_responseMetadata.GetRequestId() );
  }
  return *this;
}
