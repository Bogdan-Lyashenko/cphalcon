<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Frontend\Data;

use UnitTester;

/**
 * Class AfterRetrieveCest
 */
class AfterRetrieveCest
{
    /**
     * Tests Phalcon\Cache\Frontend\Data :: afterRetrieve()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheFrontendDataAfterRetrieve(UnitTester $I)
    {
        $I->wantToTest('Cache\Frontend\Data - afterRetrieve()');
        $I->skipTest('Need implementation');
    }
}
