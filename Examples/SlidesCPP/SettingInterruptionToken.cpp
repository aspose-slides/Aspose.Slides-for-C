#include "stdafx.h"
#include <DOM/InterruptionToken.h>
#include <DOM/InterruptionTokenSource.h>
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace Export;
using namespace System;
using namespace Threading;

void SettingInterruptionToken()
{
	//ExStart:SettingInterruptionToken

	SharedPtr<InterruptionTokenSource> tokenSource = System::MakeObject<InterruptionTokenSource>();
	std::function<void()> _local_func_0 = [&tokenSource]()
	{
		const String templatePath = u"../templates/AccessSlides.pptx";
		const String outPath = u"../out/SettingInterruptionToken_out.ppt";

		SharedPtr<LoadOptions> loadOptions = System::MakeObject<LoadOptions>();
		loadOptions->set_InterruptionToken(tokenSource->get_Token());
		SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath, loadOptions);
		pres->get_Slides()->idx_get(0)->GetThumbnail(System::Drawing::Size(960, 720));
		pres->Save(outPath, SaveFormat::Ppt);
	};

//	System::SharedPtr<System::Threading::Thread> thread = System::MakeObject<System::Threading::Thread>(static_cast<System::Threading::ThreadStart>(_local_func_0));
//	thread->Start();

//	System::Threading::Thread::Sleep(5000); // some work

//	tokenSource->Interrupt();


	//ExEnd:SettingInterruptionToken
}
