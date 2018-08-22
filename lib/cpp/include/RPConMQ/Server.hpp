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
#include <RPConMQ/Configurator.hpp>
#include <RPConMQ/Types.hpp>

namespace RPConMQ {

class IServer;
using Server = std::shared_ptr<IServer>;

/** brief IServer - Server Interface */
class IServer
{
public:
	virtual ~IServer();

	/** brief run - start the event loop */
	virtual void run() = 0;

	/** brief createInstance - Factory
 	 * details
	 * param Configurator& network configuration
	 * param service_queue& the identifier of the service queue
	 * param CallBack& the service function to expose
   * return Server instance
	 */
	static Server createInstance
	(	const Configurator& configuration,
		const std::string& service_queue,
		const CallBack&	service_callback);
};

}
