
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Factory) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Factory, phalcon, factory, phalcon_factory_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_factory_ce TSRMLS_CC, 1, phalcon_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Factory, loadClass) {

	zend_class_entry *_3$$5;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, config_sub, adapter, className, _1$$3, _2$$5;
	zval namespace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespace);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &namespace_param, &config);

	zephir_get_strval(&namespace, namespace_param);
	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/factory.zep", 27);
		return;
	}
	ZEPHIR_OBS_VAR(&adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SL("adapter"), 0)) {
		zephir_array_unset_string(config, SL("adapter"), PH_SEPARATE);
		ZEPHIR_INIT_VAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &namespace, "\\", &adapter);
		zephir_fetch_safe_class(&_2$$5, &className);
		_3$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$5), Z_STRLEN_P(&_2$$5), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _3$$5);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, config);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/factory.zep", 37);
	return;

}

