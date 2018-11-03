#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

int main(int argc, char **argv)
{
	if (argc < 3) {
		printf("USAGE %s <search_term> <output_file>", argv[0]);
		exit(EXIT_FAILURE);
	}

	const string_t searchTerm = argv[1];
	const string_t outputFileName = argv[2];

	auto fileBuffer = std::make_shared<streambuf<uint8_t>>();
	file_buffer<uint8_t>::open(outputFileName, std::ios::out)
		.then([=] (streambuf<uint8_t> outFile) -> pplx::task<http_response> {
			*fileBuffer = outFile;
			
			http_client client(U("http://www.bing.com/"));
			return client.request(methods::GET,
								  uri_builder(U("/search")).append_query(U("q"), searchTerm).to_string());
		})

		.then([=] (http_response response) -> pplx::task<size_t> {
			printf("Return status code %u returned.\n", response.status_code());
			return response.body().read_to_end(*fileBuffer);
		})

		.then([=] (size_t) {
			return fileBuffer->close();
		})

		.wait();
}


