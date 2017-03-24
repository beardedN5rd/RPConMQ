/*
 *
 * Published under Apache License, Version 2.0 (the
 * "License"); See LICENSE file or obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#pragma once
#include <RPConMQ/Types.hpp>

namespace RPConMQ {

class Configurator
{
public:
	Configurator (	const std::string& host = "127.0.0.1",
			const uint16_t port = 5672);
	virtual ~Configurator ();

	const std::string& host() const
	{
		return _host;
	}
	const std::uint16_t port() const
	{
		return _port;
	}
protected:
	std::string	_host;
	std::uint16_t	_port;
};

}
