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

#include <aws/groundstation/model/DependencyException.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace GroundStation
{
namespace Model
{

DependencyException::DependencyException() : 
    m_messageHasBeenSet(false),
    m_parameterNameHasBeenSet(false)
{
}

DependencyException::DependencyException(JsonView jsonValue) : 
    m_messageHasBeenSet(false),
    m_parameterNameHasBeenSet(false)
{
  *this = jsonValue;
}

DependencyException& DependencyException::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("message"))
  {
    m_message = jsonValue.GetString("message");

    m_messageHasBeenSet = true;
  }

  if(jsonValue.ValueExists("parameterName"))
  {
    m_parameterName = jsonValue.GetString("parameterName");

    m_parameterNameHasBeenSet = true;
  }

  return *this;
}

JsonValue DependencyException::Jsonize() const
{
  JsonValue payload;

  if(m_messageHasBeenSet)
  {
   payload.WithString("message", m_message);

  }

  if(m_parameterNameHasBeenSet)
  {
   payload.WithString("parameterName", m_parameterName);

  }

  return payload;
}

} // namespace Model
} // namespace GroundStation
} // namespace Aws
