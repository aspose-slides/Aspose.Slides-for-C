
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/Table/ITableFormatEffectiveData.h>
#include <DOM/Table/TableFormat.h>
#include <DOM/Table/ITable.h>
#include <DOM/Table/ITableFormat.h>
#include <DOM/Table/IRowFormatEffectiveData.h>
#include <DOM/Table/IRowCollection.h>
#include <DOM/Table/IRowFormat.h>
#include <DOM/Table/ICellFormatEffectiveData.h>
#include <DOM/Table/ICellFormat.h>
#include <DOM/Table/IColumnFormatEffectiveData.h>
#include <DOM/Table/IColumnCollection.h>
#include <DOM/Table/IColumnFormat.h>

#include <system/string.h>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;


void GetEffectiveValuesOfTable() {

	// ExStart:GetEffectiveValuesOfTable
	// The path to the documents directory.	
	const String templatePath = u"../templates/Presentation1.pptx";


	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	System::SharedPtr<ITable> tbl = System::DynamicCast_noexcept<Aspose::Slides::ITable>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	System::SharedPtr<ITableFormatEffectiveData> tableFormatEffective = tbl->get_TableFormat()->GetEffective();
	System::SharedPtr<IRowFormatEffectiveData> rowFormatEffective = tbl->get_Rows()->idx_get(0)->get_RowFormat()->GetEffective();
	System::SharedPtr<IColumnFormatEffectiveData> columnFormatEffective = tbl->get_Columns()->idx_get(0)->get_ColumnFormat()->GetEffective();
	System::SharedPtr<ICellFormatEffectiveData> cellFormatEffective = tbl->idx_get(0, 0)->get_CellFormat()->GetEffective();

	System::SharedPtr<IFillFormatEffectiveData> tableFillFormatEffective = tableFormatEffective->get_FillFormat();
	System::SharedPtr<IFillFormatEffectiveData> rowFillFormatEffective = rowFormatEffective->get_FillFormat();
	System::SharedPtr<IFillFormatEffectiveData> columnFillFormatEffective = columnFormatEffective->get_FillFormat();
	System::SharedPtr<IFillFormatEffectiveData> cellFillFormatEffective = cellFormatEffective->get_FillFormat();

	// ExEnd:GetEffectiveValuesOfTable

}