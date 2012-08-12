// This file implements the IPropertyDescription Interface and Gateway for Python.
// Generated by makegw.py

#include "PyIPropertyDescription.h"
#include "PyPROPVARIANT.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIPropertyDescription::PyIPropertyDescription(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIPropertyDescription::~PyIPropertyDescription()
{
}

/* static */ IPropertyDescription *PyIPropertyDescription::GetI(PyObject *self)
{
	return (IPropertyDescription *)PyIUnknown::GetI(self);
}

// @pymethod <o PyPROPERTYKEY>|PyIPropertyDescription|GetPropertyKey|Returns the unique identifier for a property
PyObject *PyIPropertyDescription::GetPropertyKey(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPERTYKEY key;
	if ( !PyArg_ParseTuple(args, ":GetPropertyKey"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetPropertyKey(&key);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyWinObject_FromPROPERTYKEY(key);
}

// @pymethod str|PyIPropertyDescription|GetCanonicalName|Returns the name of the property
PyObject *PyIPropertyDescription::GetCanonicalName(PyObject *self, PyObject *args)
{
	WCHAR *name=NULL;
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":GetCanonicalName"))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetCanonicalName(&name);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	PyObject *ret = PyWinObject_FromWCHAR(name);
	CoTaskMemFree(name);
	return ret;
}

// @pymethod int|PyIPropertyDescription|GetPropertyType|Returns the variant type of the property (VT_*)
PyObject *PyIPropertyDescription::GetPropertyType(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	VARTYPE t;
	if ( !PyArg_ParseTuple(args, ":GetPropertyType"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetPropertyType(&t);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(t);
}

// @pymethod str|PyIPropertyDescription|GetDisplayName|Returns the property name as shown in the UI
PyObject *PyIPropertyDescription::GetDisplayName(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	WCHAR *name;
	if ( !PyArg_ParseTuple(args, ":GetDisplayName"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetDisplayName(&name);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	PyObject *ret = PyWinObject_FromWCHAR(name);
	CoTaskMemFree(name);
	return ret;
}

// @pymethod str|PyIPropertyDescription|GetEditInvitation|Returns the input prompt used in edit controls
PyObject *PyIPropertyDescription::GetEditInvitation(PyObject *self, PyObject *args)
{
	WCHAR *name;
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":GetEditInvitation"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetEditInvitation(&name);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	PyObject *ret = PyWinObject_FromWCHAR(name);
	CoTaskMemFree(name);
	return ret;
}

// @pymethod int|PyIPropertyDescription|GetTypeFlags|Returns type flags for the property
PyObject *PyIPropertyDescription::GetTypeFlags(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_TYPE_FLAGS flags;
	PROPDESC_TYPE_FLAGS mask=PDTF_MASK_ALL;
	// @pyparm int|mask|PDTF_MASK_ALL|Specifies which flags to retrieve (PDTF_*)
	if ( !PyArg_ParseTuple(args, "|i:GetTypeFlags", &mask))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetTypeFlags(mask, &flags);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(flags);
}

// @pymethod int|PyIPropertyDescription|GetViewFlags|Returns the view flags that control how the property is displayed (PDVF_*)
PyObject *PyIPropertyDescription::GetViewFlags(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_VIEW_FLAGS flags;
	if ( !PyArg_ParseTuple(args, ":GetViewFlags"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetViewFlags(&flags);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(flags);
}

// @pymethod int|PyIPropertyDescription|GetDefaultColumnWidth|Returns the default width in characters
PyObject *PyIPropertyDescription::GetDefaultColumnWidth(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	UINT w;
	if ( !PyArg_ParseTuple(args, ":GetDefaultColumnWidth"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetDefaultColumnWidth(&w);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyLong_FromUnsignedLong(w);
}

// @pymethod int|PyIPropertyDescription|GetDisplayType|Returns the display type (PDDT_*)
PyObject *PyIPropertyDescription::GetDisplayType(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_DISPLAYTYPE t;
	if ( !PyArg_ParseTuple(args, ":GetDisplayType"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetDisplayType(&t);
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(t);
}

// @pymethod int|PyIPropertyDescription|GetColumnState|Returns flags that control how property is displayed in column (SHCOLSTATE_*)
PyObject *PyIPropertyDescription::GetColumnState(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	SHCOLSTATEF s;
	if ( !PyArg_ParseTuple(args, ":GetColumnState"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetColumnState(&s);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(s);
}

// @pymethod int|PyIPropertyDescription|GetGroupingRange|Returns property's grouping attributes (PDGR_*)
PyObject *PyIPropertyDescription::GetGroupingRange(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_GROUPING_RANGE g;
	if ( !PyArg_ParseTuple(args, ":GetGroupingRange"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetGroupingRange(&g);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(g);
}

// @pymethod int|PyIPropertyDescription|GetRelativeDescriptionType|Returns the relative description type (PDRDT_*)
PyObject *PyIPropertyDescription::GetRelativeDescriptionType(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_RELATIVEDESCRIPTION_TYPE d;
	if ( !PyArg_ParseTuple(args, ":GetRelativeDescriptionType"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetRelativeDescriptionType(&d);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(d);
}

// @pymethod (str, str)|PyIPropertyDescription|GetRelativeDescription|Compares two values
PyObject *PyIPropertyDescription::GetRelativeDescription(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPVARIANT *v1, *v2;
	PyObject *obv1, *obv2;
	WCHAR *desc1=NULL, *desc2=NULL;
	// @pyparm <o PyPROPVARIANT>|var1||The first value
	// @pyparm <o PyPROPVARIANT>|var2||The second value
	if ( !PyArg_ParseTuple(args, "OO:GetRelativeDescription", &obv1, &obv2))
		return NULL;
	if (!PyWinObject_AsPROPVARIANT(obv1, &v1))
		return NULL;
	if (!PyWinObject_AsPROPVARIANT(obv2, &v2))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetRelativeDescription(*v1, *v2, &desc1, &desc2);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	PyObject *ret=Py_BuildValue("NN", PyWinObject_FromWCHAR(desc1), PyWinObject_FromWCHAR(desc2));
	CoTaskMemFree(desc1);
	CoTaskMemFree(desc2);
	return ret;
}

// @pymethod int|PyIPropertyDescription|GetSortDescription|Returns value that determines how sorting options are displayed (PDSD_*)
PyObject *PyIPropertyDescription::GetSortDescription(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_SORTDESCRIPTION d;
	if ( !PyArg_ParseTuple(args, ":GetSortDescription"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetSortDescription(&d);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(d);
}

// @pymethod str|PyIPropertyDescription|GetSortDescriptionLabel|Returns description of current sort order
PyObject *PyIPropertyDescription::GetSortDescriptionLabel(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	BOOL descending;
	WCHAR *label=NULL;
	// @pyparm bool|Descending||Indicates if order is reversed
	if ( !PyArg_ParseTuple(args, "i:GetSortDescriptionLabel", &descending))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetSortDescriptionLabel(descending, &label);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	PyObject *ret=PyWinObject_FromWCHAR(label);
	CoTaskMemFree(label);
	return ret;
}

// @pymethod int|PyIPropertyDescription|GetAggregationType|Describes how properties for multiple items are displayed (PDAT_*)
PyObject *PyIPropertyDescription::GetAggregationType(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_AGGREGATION_TYPE a;
	if ( !PyArg_ParseTuple(args, ":GetAggregationType"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetAggregationType(&a);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyInt_FromLong(a);
}

// @pymethod (int, int)|PyIPropertyDescription|GetConditionType|Returns options that determine how the property is used to build a search query
// @rdesc Returns the condition type (PDCOT_*) and default operation (COP_*)
PyObject *PyIPropertyDescription::GetConditionType(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPDESC_CONDITION_TYPE t;
	CONDITION_OPERATION o;
	if ( !PyArg_ParseTuple(args, ":GetConditionType"))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetConditionType(&t, &o);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return Py_BuildValue("ii", t, o);
}

// @pymethod <o PyIPropertyEnumTypeList>|PyIPropertyDescription|GetEnumTypeList|Returns an interface used for querying valid property range
PyObject *PyIPropertyDescription::GetEnumTypeList(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	void *ret;
	IID riid = IID_IPropertyEnumTypeList;
	// @pyparm <o PyIID>|riid|IID_IPropertyEnumTypeList|IID of the requested interface

	if ( !PyArg_ParseTuple(args, "|O&:GetEnumTypeList", PyWinObject_AsIID, &riid))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->GetEnumTypeList( riid, &ret);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyCom_PyObjectFromIUnknown((IUnknown *)ret, riid);
}

// @pymethod int|PyIPropertyDescription|CoerceToCanonicalValue|Converts a variant value to the exact type expected by the property 
// @comm This method mutates the PyPROPVARIANT in place.  It may be cleared on failure. 
// @rdesc Returns the HRESULT from the operation on success.
PyObject *PyIPropertyDescription::CoerceToCanonicalValue(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPVARIANT *val;
	PyObject *obval;
	// @pyparm <o PyPROPVARIANT>|Value||The property value to be converted
	if ( !PyArg_ParseTuple(args, "O:CoerceToCanonicalValue", &obval))
		return NULL;
	if (!PyWinObject_AsPROPVARIANT(obval, &val))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->CoerceToCanonicalValue(val);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	return PyLong_FromLong(hr);
}

// @pymethod str|PyIPropertyDescription|FormatForDisplay|Converts a value to its string representation
PyObject *PyIPropertyDescription::FormatForDisplay(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPVARIANT *val;
	PROPDESC_FORMAT_FLAGS flags = PDFF_DEFAULT;
	WCHAR *display=NULL;
	PyObject *obval;
	// @pyparm <o PyPROPVARIANT>|Value||The value to be formatted
	// @pyparm int|Flags|PDFF_DEFAULT|Combination of PROPDESC_FORMAT_FLAGS (PDFF_*)
	if (!PyArg_ParseTuple(args, "O|i:FormatForDisplay", &obval, &flags))
		return NULL;
	if (!PyWinObject_AsPROPVARIANT(obval, &val))
		return NULL;

	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->FormatForDisplay(*val, flags, &display);
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIPD, IID_IPropertyDescription );
	PyObject *ret=PyWinObject_FromWCHAR(display);
	CoTaskMemFree(display);
	return ret;
}

// @pymethod bool|PyIPropertyDescription|IsValueCanonical|Determines if a value exactly matches the specification for the property
PyObject *PyIPropertyDescription::IsValueCanonical(PyObject *self, PyObject *args)
{
	IPropertyDescription *pIPD = GetI(self);
	if ( pIPD == NULL )
		return NULL;
	PROPVARIANT *val;
	// @pyparm PROPVARIANT|Value||The value to check
	if (!PyArg_ParseTuple(args, "O&:IsValueCanonical", PyWinObject_AsPROPVARIANT, &val))
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIPD->IsValueCanonical(*val);
	PY_INTERFACE_POSTCALL;
	if (hr==S_OK){
		Py_INCREF(Py_True);
		return Py_True;
		}
	Py_INCREF(Py_False);
	return Py_False;
}

// @object PyIPropertyDescription|Gives access to the details of a property definition
static struct PyMethodDef PyIPropertyDescription_methods[] =
{
	{ "GetPropertyKey", PyIPropertyDescription::GetPropertyKey, 1 }, // @pymeth GetPropertyKey|Returns the unique identifier for a property
	{ "GetCanonicalName", PyIPropertyDescription::GetCanonicalName, 1 }, // @pymeth GetCanonicalName|Returns the name of the property
	{ "GetPropertyType", PyIPropertyDescription::GetPropertyType, 1 }, // @pymeth GetPropertyType|Returns the variant type of the property (VT_*)
	{ "GetDisplayName", PyIPropertyDescription::GetDisplayName, 1 }, // @pymeth GetDisplayName|Returns the property name as shown in the UI
	{ "GetEditInvitation", PyIPropertyDescription::GetEditInvitation, 1 }, // @pymeth GetEditInvitation|Returns the input prompt used in edit controls
	{ "GetTypeFlags", PyIPropertyDescription::GetTypeFlags, 1 }, // @pymeth GetTypeFlags|Returns type flags for the property
	{ "GetViewFlags", PyIPropertyDescription::GetViewFlags, 1 }, // @pymeth GetViewFlags|Returns the view flags that control how the property is displayed (PDVF_*)
	{ "GetDefaultColumnWidth", PyIPropertyDescription::GetDefaultColumnWidth, 1 }, // @pymeth GetDefaultColumnWidth|Returns the default width in characters
	{ "GetDisplayType", PyIPropertyDescription::GetDisplayType, 1 }, // @pymeth GetDisplayType|Returns the display type (PDDT_*)
	{ "GetColumnState", PyIPropertyDescription::GetColumnState, 1 }, // @pymeth GetColumnState|Returns flags that control how property is displayed in column (SHCOLSTATE_*)
	{ "GetGroupingRange", PyIPropertyDescription::GetGroupingRange, 1 }, // @pymeth GetGroupingRange|Returns property's grouping attributes (PDGR_*)
	{ "GetRelativeDescriptionType", PyIPropertyDescription::GetRelativeDescriptionType, 1 }, // @pymeth GetRelativeDescriptionType|Returns the relative description type (PDRDT_*)
	{ "GetRelativeDescription", PyIPropertyDescription::GetRelativeDescription, 1 }, // @pymeth GetRelativeDescription|Compares two values
	{ "GetSortDescription", PyIPropertyDescription::GetSortDescription, 1 }, // @pymeth GetSortDescription|Returns value that determines how sorting options are displayed (PDSD_*)
	{ "GetSortDescriptionLabel", PyIPropertyDescription::GetSortDescriptionLabel, 1 }, // @pymeth GetSortDescriptionLabel|Returns description of current sort order
	{ "GetAggregationType", PyIPropertyDescription::GetAggregationType, 1 }, // @pymeth GetAggregationType|Describes how properties for multiple items are displayed (PDAT_*)
	{ "GetConditionType", PyIPropertyDescription::GetConditionType, 1 }, // @pymeth GetConditionType|Returns options that determine how the property is used to build a search query
	{ "GetEnumTypeList", PyIPropertyDescription::GetEnumTypeList, 1 }, // @pymeth GetEnumTypeList|Returns an interface used for querying valid property range
	{ "CoerceToCanonicalValue", PyIPropertyDescription::CoerceToCanonicalValue, 1 }, // @pymeth CoerceToCanonicalValue|Converts a variant value to the exact type expected by the property 
	{ "FormatForDisplay", PyIPropertyDescription::FormatForDisplay, 1 }, // @pymeth FormatForDisplay|Converts a value to its string representation
	{ "IsValueCanonical", PyIPropertyDescription::IsValueCanonical, 1 }, // @pymeth IsValueCanonical|Determines if a value exactly matches the specification for the property
	{ NULL }
};

PyComTypeObject PyIPropertyDescription::type("PyIPropertyDescription",
		&PyIUnknown::type,
		sizeof(PyIPropertyDescription),
		PyIPropertyDescription_methods,
		GET_PYCOM_CTOR(PyIPropertyDescription));

