# EP1 - OO 2019.2 (UnB - Gama)
#### Eduardo Nunes Pícolo (180113151)

## Descrição

O *software* possui três modos de operação: modo venda, modo recomendação e modo estoque. Para utiliza-los é preciso primeiro estar Logado como um cliente cadastrado ou como Admin (O Admin já está cadastrado no sistema). Caso o cliente não esteja cadastrado, é possivel realizar o registro.
O acesso aos modos de operação é feito pelo menu principal, que somente será mostrado apos o Login.

### Cadastro
Realizar o cadastro de um novo cliente.

Para cadastrar-se, insira o CPF, que será verificado, nome, senha, email e telefone.

Ao finalizar o cadastrado, o cliente estará automaticamente Logado.

### Login
O login é obrigatório para o uso das outras funcionalidades.

Para entar, digite o CPF e a senha.

O CPF do Admin é '98765432100' e a senha é 'admin'.

### Modo venda
O modo venda permite ao cliente escolher produtos e adiciona-los ao seu carrinho.

Primeiro, o cliente escolhe uma categoria dentre as categoria listadas e então seleciona o índice do produto que deseja comprar, em seguida será dada a opção para continuar comprando, confirmar a compra ou cancelar a compra e retornar ao menu principal.

Caso a comprar seja confirmada, será listado os produtos do carrinho, seus respectivos preços e quantidades adquiridas, e o total da compra.

Se o cliente tiver o status de VIP, receberá um disconto de 15% no total.

### Modo recomendação
As recomendações serão feitas a partir do histórico de compras do cliente, mais especificamente, das categorias que o mesmo mais compra.

Ao acessar o modo recomendação, pelo menu principal, será listado até 10 produtos, cada um pertencente a uma categoria.

Caso o cliente não possua um histórico de compras, nenhum produto será recomendado.

Para comprar algum produto recomendado, acesse o modo venda.

### Perfil
No perfil é possivel editar dados do cliente.

Não é possivel alterar o CPF, somente senha, nome, email e telefone.

Também há a opção de 'tornar-se VIP', para clientes frequentes e que possuem um certo histórico de compras. O status de VIP dá um desconto de 15% em todas as compras.

### Modo estoque
Somente o Admin tem acesso ao estoque.

Aqui, é possivel registrar novos produtos e reabaster o estoque.

Para registrar um novo produto basta inserir o nome do produto, categoria, preço e quantidade. Caso a categoria não exista, ela será criada automaticamente.

Para reabastecer um produto no estoque, insira o nome do produto e a quantidade que será adicionada ao respectivo produto.