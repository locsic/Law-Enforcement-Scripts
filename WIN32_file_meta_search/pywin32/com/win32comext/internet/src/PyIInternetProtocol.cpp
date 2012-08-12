// This file implements the IInternetProtocol Interface and Gateway for Python.
// Generated by makegw.py

#include "internet_pch.h"
#include "PyIInternetProtocolRoot.h"
#include "PyIInternetProtocol.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIInternetProtocol::PyIInternetProtocol(IUnknown *pdisp):
	PyIInternetProtocolRoot(pdisp)
{
	ob_type = &type;
}

PyIInternetProtocol::~PyIInternetProtocol()
{
}

/* static */ IInternetProtocol *PyIInternetProtocol::GetI(PyObject *self)
{
	return (IInternetProtocol *)PyIInternetProtocolRoot::GetI(self);
}

// @pymethod |PyIInternetProtocol|Read|Description of Read.
PyObject *PyIInternetProtocol::Read(PyObject *self, PyObject *args)
{
	IInternetProtocol *pIIP = GetI(self);
	if ( pIIP == NULL )
		return NULL;
	// @pyparm int|cb||Description for cb
	ULONG cb;
	ULONG pcbRead;
	if ( !PyArg_ParseTuple(args, "i:Read", &cb) )
		return NULL;
	HRESULT hr;
	void *pv = malloc(cb);
	PY_INTERFACE_PRECALL;
	hr = pIIP->Read( pv, cb, &pcbRead );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) ) {
		free(pv);
		return OleSetOleError(hr);
	}

	PyObject *pyretval = PyString_FromStringAndSize((char *)pv, pcbRead );
	free(pv);
	return pyretval;
}

// @pymethod |PyIInternetProtocol|Seek|Description of Seek.
PyObject *PyIInternetProtocol::Seek(PyObject *self, PyObject *args)
{
	IInternetProtocol *pIIP = GetI(self);
	if ( pIIP == NULL )
		return NULL;
	// @pyparm <o LARGE_INTEGER>|dlibMove||Description for dlibMove
	// @pyparm int|dwOrigin||Description for dwOrigin
	PyObject *obdlibMove;
	LARGE_INTEGER dlibMove;
	DWORD dwOrigin;
	ULARGE_INTEGER plibNewPosition;
	if ( !PyArg_ParseTuple(args, "Oi:Seek", &obdlibMove, &dwOrigin) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyWinObject_AsLARGE_INTEGER(obdlibMove, &dlibMove)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIP->Seek( dlibMove, dwOrigin, &plibNewPosition );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	PyObject *obplibNewPosition;

	obplibNewPosition = PyWinObject_FromULARGE_INTEGER(plibNewPosition);
	PyObject *pyretval = Py_BuildValue("O", obplibNewPosition);
	Py_XDECREF(obplibNewPosition);
	return pyretval;
}

// @pymethod |PyIInternetProtocol|LockRequest|Description of LockRequest.
PyObject *PyIInternetProtocol::LockRequest(PyObject *self, PyObject *args)
{
	IInternetProtocol *pIIP = GetI(self);
	if ( pIIP == NULL )
		return NULL;
	// @pyparm int|dwOptions||Description for dwOptions
	DWORD dwOptions;
	if ( !PyArg_ParseTuple(args, "i:LockRequest", &dwOptions) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIP->LockRequest( dwOptions );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIInternetProtocol|UnlockRequest|Description of UnlockRequest.
PyObject *PyIInternetProtocol::UnlockRequest(PyObject *self, PyObject *args)
{
	IInternetProtocol *pIIP = GetI(self);
	if ( pIIP == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":UnlockRequest") )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIP->UnlockRequest( );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @object PyIInternetProtocol|Description of the interface
static struct PyMethodDef PyIInternetProtocol_methods[] =
{
	{ "Read", PyIInternetProtocol::Read, 1 }, // @pymeth Read|Description of Read
	{ "Seek", PyIInternetProtocol::Seek, 1 }, // @pymeth Seek|Description of Seek
	{ "LockRequest", PyIInternetProtocol::LockRequest, 1 }, // @pymeth LockRequest|Description of LockRequest
	{ "UnlockRequest", PyIInternetProtocol::UnlockRequest, 1 }, // @pymeth UnlockRequest|Description of UnlockRequest
	{ NULL }
};

PyComTypeObject PyIInternetProtocol::type("PyIInternetProtocol",
		&PyIInternetProtocolRoot::type,
		sizeof(PyIInternetProtocol),
		PyIInternetProtocol_methods,
		GET_PYCOM_CTOR(PyIInternetProtocol));
// ---------------------------------------------------
//
// Gateway Implementation

// Std delegation
STDMETHODIMP PyGInternetProtocol::Start(LPCWSTR szUrl,	IInternetProtocolSink __RPC_FAR * pOIProtSink, IInternetBindInfo __RPC_FAR * pOIBindInfo, DWORD grfPI, HANDLE_PTR dwReserved)
	{ return PyGInternetProtocolRoot::Start(szUrl, pOIProtSink, pOIBindInfo, grfPI, dwReserved);}

STDMETHODIMP PyGInternetProtocol::Continue(PROTOCOLDATA __RPC_FAR * pProtocolData)
	{return PyGInternetProtocolRoot::Continue(pProtocolData);}

STDMETHODIMP PyGInternetProtocol::Abort(HRESULT hrReason, DWORD dwOptions)
	{return PyGInternetProtocolRoot::Abort(hrReason, dwOptions);}

STDMETHODIMP PyGInternetProtocol::Terminate(DWORD dwOptions)
	{return PyGInternetProtocolRoot::Terminate(dwOptions);}

STDMETHODIMP PyGInternetProtocol::Suspend(void)
	{return PyGInternetProtocolRoot::Suspend();}

STDMETHODIMP PyGInternetProtocol::Resume(void)
	{return PyGInternetProtocolRoot::Resume();}

STDMETHODIMP PyGInternetProtocol::Read(
		/* [length_is][size_is][out][in] */ void __RPC_FAR * pv,
		/* [in] */ ULONG cb,
		/* [out] */ ULONG __RPC_FAR * pcbRead)
{
	if (pcbRead==NULL) return E_POINTER;
	*pcbRead = 0;
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("Read", &result, "l", cb);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyString_Check(result)) {
		PyErr_SetString(PyExc_TypeError, "IInternetProtocol::Read must return a string object");
		hr = PyCom_HandlePythonFailureToCOM();
	} else {
		char *buf = PyString_AsString(result);
		*pcbRead = min(cb, (ULONG)PyString_Size(result));
		memcpy( pv, buf, *pcbRead);
	}
	return hr;
}

STDMETHODIMP PyGInternetProtocol::Seek(
		/* [in] */ LARGE_INTEGER dlibMove,
		/* [in] */ DWORD dwOrigin,
		/* [out] */ ULARGE_INTEGER __RPC_FAR * plibNewPosition)
{
	PY_GATEWAY_METHOD;
	PyObject *obdlibMove;
	obdlibMove = PyWinObject_FromLARGE_INTEGER(dlibMove);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("Seek", &result, "Oi", obdlibMove, dwOrigin);
	Py_XDECREF(obdlibMove);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obplibNewPosition;
	if (!PyArg_Parse(result, "O" , &obplibNewPosition)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	BOOL bPythonIsHappy = TRUE;
	if (!PyWinObject_AsULARGE_INTEGER(obplibNewPosition, plibNewPosition)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGInternetProtocol::LockRequest(
		/* [in] */ DWORD dwOptions)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("LockRequest", NULL, "i", dwOptions);
	return hr;
}

STDMETHODIMP PyGInternetProtocol::UnlockRequest(
		void)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("UnlockRequest", NULL);
	return hr;
}

