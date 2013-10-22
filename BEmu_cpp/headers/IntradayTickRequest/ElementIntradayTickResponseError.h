//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/IntradayTickRequest/ElementIntradayTickResponseError.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#include "bemu_headers.h"
#include "BloombergTypes\Name.h"
#include "BloombergTypes\Element.h"
#include "BloombergTypes\ElementPtr.h"
#include "BloombergTypes\Datetime.h"

#include "IntradayTickRequest\ElementIntradayTickString.h"
#include "IntradayTickRequest\ElementIntradayTickInt.h"

#pragma once

namespace BEmu
{
	namespace IntradayTickRequest
	{
		class MessageIntradayTick;

		class ElementIntradayTickResponseError : private ElementPtr
		{
			private:
				ElementIntradayTickString *_source, *_category, *_message, *_subCategory;
				ElementIntradayTickInt *_code;
				ElementIntradayTickResponseError();
				~ElementIntradayTickResponseError();

			public:
				virtual Name name() const;
				virtual int numValues() const { return 1; }
				virtual int numElements() const { return 5; }		
				virtual bool isArray() const { return false; }
				virtual bool isComplexType() const { return true; }
				
				virtual const char* getElementAsString(const char* name) const;
				virtual int getElementAsInt32(const char* name) const;
				virtual ElementPtr * getElement(const char* name) const;
				virtual bool hasElement(const char* name, bool excludeNullElements = false) const;

				virtual std::ostream& print(std::ostream& stream, int level = 0, int spacesPerLevel = 4) const;

				friend class MessageIntradayTick; //The MessageIntradayTick constructor needs access to the ElementIntradayTickResponseError constructor
		};
	}
}