<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Bag;

use IntegrationTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Session\Bag :: remove()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagRemove(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - remove()");
        $session = new \Phalcon\Session\Bag("RemoveTest");

        $testValue = "TestValue";
        $session->set("test", $testValue);
        $session->remove("test");

        $I->assertFalse($session->has("test"));
    }
}