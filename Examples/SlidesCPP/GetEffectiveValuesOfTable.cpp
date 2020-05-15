#include "stdafx.h"
#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void GetEffectiveValuesOfTable() {

	// ExStart:GetEffectiveValuesOfTable
	// The path to the documents directory.	
	const String templatePath = u"../templates/TestTable.pptx";

	SharedPtr<Presentation> pres = System::MakeObject<Presentation>(templatePath);
	SharedPtr<ITable> tbl = System::DynamicCast_noexcept<ITable>(pres->get_Slides()->idx_get(0)->get_Shapes()->idx_get(0));
	SharedPtr<ITableFormatEffectiveData> tableFormatEffective = tbl->get_TableFormat()->GetEffective();
	SharedPtr<IRowFormatEffectiveData> rowFormatEffective = tbl->get_Rows()->idx_get(0)->get_RowFormat()->GetEffective();
	SharedPtr<IColumnFormatEffectiveData> columnFormatEffective = tbl->get_Columns()->idx_get(0)->get_ColumnFormat()->GetEffective();
	SharedPtr<ICellFormatEffectiveData> cellFormatEffective = tbl->idx_get(0, 0)->get_CellFormat()->GetEffective();

	SharedPtr<IFillFormatEffectiveData> tableFillFormatEffective = tableFormatEffective->get_FillFormat();
	SharedPtr<IFillFormatEffectiveData> rowFillFormatEffective = rowFormatEffective->get_FillFormat();
	SharedPtr<IFillFormatEffectiveData> columnFillFormatEffective = columnFormatEffective->get_FillFormat();
	SharedPtr<IFillFormatEffectiveData> cellFillFormatEffective = cellFormatEffective->get_FillFormat();

	// ExEnd:GetEffectiveValuesOfTable
}
