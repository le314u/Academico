module.exports = class E  extends Error{
    constructor(name="Erro genérico", condition="Condição não especificada", ...params){
        super(...params)
        super.name = 'Erro '+name
        super.message = `\nCausa: ${condition}\n`;                
        this.debug=params
    }
}