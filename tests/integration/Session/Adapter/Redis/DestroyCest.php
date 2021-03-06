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

namespace Phalcon\Test\Integration\Session\Adapter\Redis;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use function uniqid;

/**
 * Class DestroyCest
 */
class DestroyCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Redis :: destroy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterRedisDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Redis - destroy()');
        $adapter = $this->getSessionRedis();

        $value      = uniqid();
        $serialized = serialize($value);
        $I->haveInRedis('string', 'test1', $serialized);
        $actual = $adapter->destroy('test1');
        $I->assertTrue($actual);
        $I->dontSeeInRedis('test1');
    }
}
