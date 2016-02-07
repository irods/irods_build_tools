// =-=-=-=-=-=-=-
#include "apiHeaderAll.hpp"
#include "msParam.hpp"
#include "reGlobalsExtern.hpp"
#include "irods_ms_plugin.hpp"
#include "irods_file_object.hpp"
#include "irods_resource_redirect.hpp"
#include "irods_hierarchy_parser.hpp"

// =-=-=-=-=-=-=-
#include <string>
#include <iostream>
#include <vector>

extern "C" {

    double get_plugin_interface_version() {
        return 1.0;
    }

    int validate_and_unpack(
        msParam_t*      _str_ms_param,
        msParam_t*      _int_ms_param,
        msParam_t*      _double_ms_param,
        rError_t*       _error_out,
        std::string&    _str_out,
        int&            _int_out,
        double&         _double_out ) {

        if( !_str_ms_param ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " null _str_ms_param parameter";
            addRErrorMsg(
                _error_out,
                SYS_NULL_INPUT,
                msg.str().c_str() );
            return SYS_NULL_INPUT;
        }

        if( !_int_ms_param ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " null _int_ms_param parameter";
            addRErrorMsg(
                _error_out,
                SYS_NULL_INPUT,
                msg.str().c_str() );
            return SYS_NULL_INPUT;
        }

        if( !_double_ms_param ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " null _double_ms_param parameter";
            addRErrorMsg(
                _error_out,
                SYS_NULL_INPUT,
                msg.str().c_str() );
            return SYS_NULL_INPUT;
        }

        char* str_param = parseMspForStr( _str_ms_param );
        if( !str_param ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " failed to unpack _str_ms_param parameter";
            addRErrorMsg(
                _error_out,
                USER_PARAM_TYPE_ERR,
                msg.str().c_str() );
            return USER_PARAM_TYPE_ERR;
        }
        _str_out = str_param;

        _int_out = parseMspForPosInt( _int_ms_param );
        if( _int_out < 0 ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " failed to unpack _int_ms_param parameter";
            addRErrorMsg(
                _error_out,
                _int_out,
                msg.str().c_str() );
            return _int_out;
        }

        int ret = parseMspForDouble( _double_ms_param, &_double_out );
        if( ret < 0 ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " failed to unpack _double_ms_param parameter";
            addRErrorMsg(
                _error_out,
                ret,
                msg.str().c_str() );
            return ret;
        }

        return 0;

    } // validate_and_unpack

    int msitest_one(
        msParam_t*      _str_ms_param,
        msParam_t*      _int_ms_param,
        msParam_t*      _double_ms_param,
        ruleExecInfo_t* _rei ) {
        if( !_rei ) {
            std::stringstream msg;
            msg << __FUNCTION__
                << " null rei parameter";
            addRErrorMsg(
                &_rei->rsComm->rError,
                SYS_NULL_INPUT,
                msg.str().c_str() );
            return SYS_NULL_INPUT;
        }

        int int_param = 0;
        double double_param = 0.0f;
        std::string str_param;
        int ret = validate_and_unpack(
                      _str_ms_param,
                      _int_ms_param,
                      _double_ms_param,
                      &_rei->rsComm->rError,
                      str_param,
                      int_param,
                      double_param ); 
        if( ret < 0 ) {
           return ret;
        }

        // something interesting happens here
        std::cout << "str_param    [" << str_param   << "]" << std::endl;
        std::cout << "int_param    [" << int_param   << "]" << std::endl;
        std::cout << "double_param [" << double_param << "]" << std::endl;

        return 0; 

    }

    irods::ms_table_entry* plugin_factory() {
        irods::ms_table_entry* msvc = new irods::ms_table_entry(3);
        msvc->add_operation("msitest_one", "msitest_one");
        return msvc;
    }

} // extern "C"

