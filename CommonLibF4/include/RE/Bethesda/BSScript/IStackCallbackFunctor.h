#pragma once



#include "RE/Bethesda/BSTSmartPointer.h"  // BSIntrusiveRefCounted


namespace RE
{
	namespace BSScript
	{
		class Variable;


		class __declspec(novtable) IStackCallbackFunctor : 
			public BSIntrusiveRefCounted
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IStackCallbackFunctor };
			static constexpr auto VTABLE{ VTABLE::BSScript__IStackCallbackFunctor };


			IStackCallbackFunctor();
			virtual ~IStackCallbackFunctor() = default;			// 00

			// add
			virtual void operator()(Variable a_result) = 0;                       // 01
			virtual bool CanSave() const;                                         // 02 - { return false; }
			virtual void SetObject(const BSTSmartPointer<Object>& a_object) = 0;  // 03

			// members
			std::uint32_t unk0C;	// 0C
		};
		static_assert(sizeof(IStackCallbackFunctor) == 0x10);
	}
}
