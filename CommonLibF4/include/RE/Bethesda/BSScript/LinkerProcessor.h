#pragma once



#include "RE/Bethesda/BSScript/IObjectProcessor.h"  // BSScript::IObjectProcessor
#include "RE/Bethesda/BSFixedString.h"  // BSFixedString
#include "RE/Bethesda/BSTArray.h"  // BSScrapArray
// #include "RE/Bethesda/BSTHashMap.h"  // BSTHashMap
#include "RE/Bethesda/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		// class Class;
		class ErrorLogger;


		namespace Internal
		{
			class VirtualMachine;
		}


		class __declspec(novtable) LinkerProcessor : 
			public IObjectProcessor
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__LinkerProcessor };
			static constexpr auto VTABLE{ VTABLE::BSScript__LinkerProcessor };


			virtual ~LinkerProcessor();														// 00

			// override (IObjectProcessor)
			virtual IObjectProcessor*	Clone() override;                                    // 01
			virtual void				      SetLoader(ILoader* a_loader) override;               // 02 - { loader = a_loader; }
			virtual bool				      Process(const BSFixedString& a_className) override;  // 03


			// members
			Internal::VirtualMachine*							virtualMachine;	// 08
			ErrorLogger*										errorLogger;	// 10
			ILoader*											loader;			// 18
			std::uint64_t												unk20;			// 20

			// TODO:
			char												temp[104];
			//BSScrapArray<BSFixedString>							unk28;			// 28
			//BSScrapArray<BSFixedString>							unk48;			// 48
			//BSScrapArray<BSFixedString>							unk68;			// 68
			//BSTHashMap<BSFixedString, BSTSmartPointer<Class>>*	classMap;		// 88
		};
		static_assert(sizeof(LinkerProcessor) == 0x90);
	}
}
