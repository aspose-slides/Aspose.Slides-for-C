

#include <system/object_ext.h>
#include<Dom/LoadOptions.h>
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/ISlide.h>
#include<Dom/InterruptionToken.h>
#include<Dom/InterruptionTokenSource.h>
#include <Export/SaveFormat.h>
#include<Dom/CommonSlideViewProperties.h>
#include "SlidesExamples.h"

using namespace Aspose;
using namespace Aspose::Slides;
using namespace Aspose::Slides::Export;
using namespace System;
using namespace System::Threading;

void SettingInterruptionToken() {

	//ExStart:SettingInterruptionToken


	System::SharedPtr<InterruptionTokenSource> tokenSource = System::MakeObject<InterruptionTokenSource>();
	std::function<void()> _local_func_0 = [&tokenSource]()
	{
		const String templatePath = u"../templates/AccessSlides.pptx";
		const String outPath = u"../out/SettingInterruptionToken_out.ppt";

		System::SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
		loadOptions->set_InterruptionToken(tokenSource->get_Token());
		System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath, loadOptions);
		pres->get_Slides()->idx_get(0)->GetThumbnail(System::Drawing::Size(960, 720));
		pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Ppt);
	};

//	System::SharedPtr<System::Threading::Thread> thread = System::MakeObject<System::Threading::Thread>(static_cast<System::Threading::ThreadStart>(_local_func_0));
//	thread->Start();

//	System::Threading::Thread::Sleep(5000); // some work

//	tokenSource->Interrupt();


	//ExEnd:SettingInterruptionToken

}