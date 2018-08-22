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

class IClient;
using Client = std::shared_ptr<IClient>;

/** brief IClient - Client Interface */
class IClient
{
protected:
	IClient ();
public:
	virtual ~IClient ();
		/** brief request - send a request to the service
		 * param Request& the message to send
		 * return Response
		 */
	virtual Response request (const Request& request) = 0;

	/** brief createInstance - Factory
 	 * details
	 * param init_data& atm a amqp specific string
	 * param service_queue& the identifier of the service queue
	 * param CorrelationCallBack& the correlation function that should be used
   * return Client instance
	 */
	static Client createInstance
	(	const std::string& init_data,
		const std::string& service_queue,
	  const CorrelationCallBack& correlation_callback);
};

}
